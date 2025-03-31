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

	// COM ��� ����
	hr = CoInitialize(NULL);

	if (SUCCEEDED(hr))
	{
		/*	��ġ�� ���ε����� ���� ���ҽ��� ����ϴ�.������ ���� ���ӵǴ� ���� ȿ�������� ����˴ϴ�.
			�̷��� ���ҽ����� Direct2D �� DirectWrite ���͸���
			DirectWrite �ؽ�Ʈ ���� ��ü(Ư�� �۲� Ư���� �ĺ��ϴ� �� ����)�� ���Ե˴ϴ�.
		*/
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);
	}
	if (SUCCEEDED(hr))
	{
		// DirectWrite ���͸��� ����ϴ�.
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(m_pDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_pDWriteFactory));
	}
	if (SUCCEEDED(hr))
	{
		// DirectWrite �ؽ�Ʈ ���� ��ü�� ����ϴ�.
		hr = m_pDWriteFactory->CreateTextFormat(
			L"", // FontName    ������-���������-�׸�-�۲�-Ŭ�� ���� �۲��̸� Ȯ�ΰ���
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
		Direct3D ��ġ�� ���ε��� ���ҽ��� ����ϴ�.
		Direct3D ��ġ�� �սǵ� ���(��: ���÷��� ����, ����, ���� ī�� ���� ��)
		���ҽ��� �ٽ� �����ؾ� �ϴ� ��츦 ����Ͽ� ��� ���⿡ �߾� ����ȭ�Ǿ� �ֽ��ϴ�.
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
	// VRAM ������� ���� ��ü ����
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
	// �߾� �������� �׸���
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


	// ������ ����Ҷ����� �ٽ� �����.
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

	// DirectWrite �ؽ�Ʈ ���� ��ü�� ����ϴ�.
	HRESULT hr = m_pDWriteFactory->CreateTextFormat(
		fontName, // FontName    ������-���������-�׸�-�۲�-Ŭ�� ���� �۲��̸� Ȯ�ΰ���
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