#include "pch.h"
#include "D2DRenderer.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"windowscodecs.lib")

D2DRenderer::D2DRenderer()
{

}

D2DRenderer::~D2DRenderer()
{

}

D2DRenderer* D2DRenderer::pInstance = nullptr;
D2D1_MATRIX_3X2_F D2DRenderer::mCameraTransform = D2D1::Matrix3x2F::Identity();

void D2DRenderer::Initialize(HWND hWnd)
{
	mHWnd = hWnd;
	HRESULT hr = S_OK;

	// COM 사용 시작
	hr = CoInitialize(NULL);

	if (SUCCEEDED(hr))
	{
		/*	장치에 바인딩되지 않은 리소스를 만듭니다.수명은 앱이 지속되는 동안 효과적으로 연장됩니다.
			이러한 리소스에는 Direct2D 및 DirectWrite 팩터리와
			DirectWrite 텍스트 형식 개체(특정 글꼴 특성을 식별하는 데 사용됨)가 포함됩니다.
		*/
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);
	}
	if (SUCCEEDED(hr))
	{
		// DirectWrite 팩터리를 만듭니다.
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(m_pDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_pDWriteFactory));
	}
	if (SUCCEEDED(hr))
	{
		// DirectWrite 텍스트 형식 개체를 만듭니다.
		hr = m_pDWriteFactory->CreateTextFormat(
			L"", // FontName    제어판-모든제어판-항목-글꼴-클릭 으로 글꼴이름 확인가능
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			20.0f,   // Font Size
			L"", //locale
			&m_pDWriteTextFormat
		);
	}
	if (SUCCEEDED(hr))
	{
		/*
		Direct3D 장치에 바인딩된 리소스를 만듭니다.
		Direct3D 장치가 손실된 경우(예: 디스플레이 변경, 원격, 비디오 카드 제거 등)
		리소스를 다시 생성해야 하는 경우를 대비하여 모두 여기에 중앙 집중화되어 있습니다.
		*/

		// Create a Direct2D render target
		RECT rc;
		GetClientRect(mHWnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top);

		hr = m_pD2DFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(mHWnd, size),
			&m_pRenderTarget);
	}
	if (SUCCEEDED(hr))
	{
		hr = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_pBrush);
	}
	if (SUCCEEDED(hr))
	{
		// Create WIC factory
		hr = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&m_pWICFactory)
		);
	}
	// VRAM 정보얻기 위한 개체 생성
	if (SUCCEEDED(hr))
	{
		// Create DXGI factory
		hr = CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)&m_pDXGIFactory);
	}
	if (SUCCEEDED(hr))
	{
		m_pDXGIFactory->EnumAdapters(0, reinterpret_cast<IDXGIAdapter**>(&m_pDXGIAdapter));
	}
}

void D2DRenderer::Uninitialize()
{
	SAFE_RELEASE(m_pBrush);
	SAFE_RELEASE(m_pRenderTarget);
	SAFE_RELEASE(m_pD2DFactory);
	SAFE_RELEASE(m_pWICFactory);
	SAFE_RELEASE(m_pDWriteFactory);
	SAFE_RELEASE(m_pDWriteTextFormat);
	SAFE_RELEASE(m_pDXGIFactory);
	SAFE_RELEASE(m_pDXGIAdapter);

	CoUninitialize();
}

void D2DRenderer::BeginDraw()
{
	m_pRenderTarget->BeginDraw();
}

void D2DRenderer::EndDraw()
{
	m_pRenderTarget->EndDraw();
}

void D2DRenderer::DrawBitmap(ID2D1Bitmap* const ID2D1Bitmap, const D2D1_MATRIX_3X2_F& matrix)
{
	m_pRenderTarget->SetTransform(matrix);
	m_pRenderTarget->DrawBitmap(ID2D1Bitmap);
}

void D2DRenderer::DrawRect(const D2D1_RECT_F& rectPoint, const D2D1_COLOR_F& color, bool rectFill, float alpha)
{
	m_pBrush->SetColor(color);
	m_pBrush->SetOpacity(alpha);

	if (rectFill)
	{
		m_pRenderTarget->DrawRectangle(&rectPoint, m_pBrush);
	}
	else
	{
		m_pRenderTarget->FillRectangle(&rectPoint, m_pBrush);
	}
}

void D2DRenderer::DrawRect(const D2D1_VECTOR_2F& position, const D2D1_SIZE_F& rectSize, const D2D1_COLOR_F& color, bool rectFill, float alpha)
{
	// 중앙 기준으로 그리기
	float halfWidth = rectSize.width * 0.5f;
	float halfHeight = rectSize.height * 0.5f;

	D2D1_RECT_F rectPoint{};
	rectPoint.left = position.x - halfWidth;
	rectPoint.top = position.y - halfHeight;
	rectPoint.right = position.x + halfWidth;
	rectPoint.bottom = position.y + halfHeight;

	m_pBrush->SetColor(color);
	m_pBrush->SetOpacity(alpha);

	if (rectFill)
	{
		m_pRenderTarget->DrawRectangle(rectPoint, m_pBrush);
	}
	else
	{
		m_pRenderTarget->FillRectangle(rectPoint, m_pBrush);
	}
}

void D2DRenderer::DrawTextW(const wchar_t* text, IDWriteTextFormat*& fontFormat, const D2D1_RECT_F& drawRect, const D2D1_COLOR_F& color, float alpha)
{
	m_pBrush->SetColor(color);
	m_pBrush->SetOpacity(alpha);

	size_t bufferSize = wcslen(text);

	m_pRenderTarget->DrawText(text, bufferSize, fontFormat, drawRect, m_pBrush);
}

void D2DRenderer::DrawLine(const D2D1_POINT_2F startPoint, const D2D1_POINT_2F endPoint, const D2D1_COLOR_F& color, float alpha, float lineWidth)
{
	m_pBrush->SetColor(color);
	m_pBrush->SetOpacity(alpha);

	m_pRenderTarget->DrawLine(startPoint, endPoint, m_pBrush, lineWidth);
}

void D2DRenderer::PrintMatrix(const wchar_t* str, D2D_MATRIX_3X2_F& mat, float left, float top)
{
	WCHAR buffer[256] = { 0 };
	swprintf_s(buffer, L"%.2f, %.2f\n%.2f, %.2f\n%.2f, %.2f\n",
		mat._11, mat._12, mat._21, mat._22, mat._31, mat._32);
	OutputDebugString(buffer);

	D2D1::Matrix3x2F matRender = D2D1::Matrix3x2F::Identity();
	m_pRenderTarget->SetTransform(matRender);

	m_pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::White));
	m_pRenderTarget->FillRectangle(D2D1::RectF(left, top, left + 150, top + 150), m_pBrush);

	m_pBrush->SetColor(D2D1::ColorF(D2D1::ColorF::HotPink));
	m_pRenderTarget->DrawTextW(str, (UINT32)wcslen(str), m_pDWriteTextFormat, D2D1::RectF(left, top, left + 300, top + 300), m_pBrush);
	m_pRenderTarget->DrawTextW(buffer, (UINT32)wcslen(buffer), m_pDWriteTextFormat, D2D1::RectF(left, top + 60, left + 300, top + 60 + 300), m_pBrush);
}

void D2DRenderer::Clear(const D2D1_COLOR_F& color)
{
	m_pRenderTarget->Clear(color);
}

size_t D2DRenderer::GetUsedVRAM()
{
	DXGI_QUERY_VIDEO_MEMORY_INFO videoMemoryInfo;
	m_pDXGIAdapter->QueryVideoMemoryInfo(0, DXGI_MEMORY_SEGMENT_GROUP_LOCAL, &videoMemoryInfo);
	return videoMemoryInfo.CurrentUsage / 1024 / 1024;
}

HRESULT D2DRenderer::CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap)
{
	HRESULT hr;
	// Create a decoder
	IWICBitmapDecoder* pDecoder = NULL;
	IWICFormatConverter* pConverter = NULL;

	hr = m_pWICFactory->CreateDecoderFromFilename(
		szFilePath,                      // Image to be decoded
		NULL,                            // Do not prefer a particular vendor
		GENERIC_READ,                    // Desired read access to the file
		WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
		&pDecoder                        // Pointer to the decoder
	);

	// Retrieve the first frame of the image from the decoder
	IWICBitmapFrameDecode* pFrame = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pFrame);
	}

	//Step 3: Format convert the frame to 32bppPBGRA
	if (SUCCEEDED(hr))
	{
		hr = m_pWICFactory->CreateFormatConverter(&pConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pConverter->Initialize(
			pFrame,                          // Input bitmap to convert
			GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
			WICBitmapDitherTypeNone,         // Specified dither pattern
			NULL,                            // Specify a particular palette 
			0.f,                             // Alpha threshold
			WICBitmapPaletteTypeCustom       // Palette translation type
		);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppID2D1Bitmap);
	}


	// 파일을 사용할때마다 다시 만든다.
	if (pConverter)
		pConverter->Release();

	if (pDecoder)
		pDecoder->Release();

	if (pFrame)
		pFrame->Release();

	return hr;
}

IDWriteTextFormat* D2DRenderer::CreateD2DFont(const wchar_t* fontName, float fontSize, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch)
{
	IDWriteTextFormat* pDWriteTextFormat = nullptr;

	// DirectWrite 텍스트 형식 개체를 만듭니다.
	HRESULT hr = m_pDWriteFactory->CreateTextFormat(
		fontName, // FontName    제어판-모든제어판-항목-글꼴-클릭 으로 글꼴이름 확인가능
		NULL,
		fontWeight,
		fontStyle,
		fontStretch,
		fontSize,   // Font Size
		L"", //locale
		&pDWriteTextFormat
	);
	if (FAILED(hr))
	{
		_com_error err(hr);
		::MessageBox(GetActiveWindow(), err.ErrorMessage(), L"Error CreateD2DFont", MB_OK);
		return nullptr;
	}

	return pDWriteTextFormat;
}