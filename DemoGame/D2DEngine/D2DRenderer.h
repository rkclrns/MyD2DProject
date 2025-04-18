#pragma once
#include "pch.h"
#include <d2d1.h>

class D2DRenderer
{
public:
	static D2D1_MATRIX_3X2_F mCameraTransform;		// 카메라 월드 역행렬
	
	static D2DRenderer* GetInstance()
	{
		if (!pInstance)
			pInstance = new D2DRenderer();

		return pInstance;
	}

	static void DestroyInstance() {
		delete pInstance;  // 해제
		pInstance = nullptr;
	}

	void					Initialize(HWND hWnd);
	void					Uninitialize();

	void					BeginDraw();
	void					EndDraw();

	void					DrawBitmap(ID2D1Bitmap* const ID2D1Bitmap, const D2D1_MATRIX_3X2_F& matrix);

	void					DrawRect(const D2D1_RECT_F& rectPoint, const D2D1_COLOR_F& color, bool rectFill, float alpha = 1.f);
	void					DrawRect(const D2D1_MATRIX_3X2_F& matrix, const D2D1_RECT_F& rectPoint, const D2D1_COLOR_F& color, bool rectFill, float alpha = 1.f);
	void					DrawRect(const D2D1_VECTOR_2F& position, const D2D1_SIZE_F& rectSize, const D2D1_COLOR_F& color, bool rectFill, float alpha = 1.f);
	void					DrawRect(const D2D1_MATRIX_3X2_F& matrix, const D2D1_VECTOR_2F& position, const D2D1_SIZE_F& rectSize, const D2D1_COLOR_F& color, bool rectFill, float alpha = 1.f);
	void					DrawTextW(const wchar_t* text, IDWriteTextFormat* fontFormat, const D2D1_RECT_F& drawRect, const D2D1_COLOR_F& color, float alpha = 1.f);
	void					DrawTextW(const wchar_t* text, IDWriteTextFormat* fontFormat, const D2D1_RECT_F& drawRect, const D2D1_MATRIX_3X2_F& matrix, const D2D1_COLOR_F& color, float alpha = 1.f);
	void					DrawLine(const D2D1_POINT_2F startPoint, const D2D1_POINT_2F endPoint, const D2D1_COLOR_F& color, float alpha = 1.f, float lineWidth = 1.f);

	ID2D1Factory*			GetFactory() { return m_pD2DFactory; }
	ID2D1HwndRenderTarget*	GetRenderTarget() { return m_pRenderTarget; }
	size_t					GetUsedVRAM();

	HRESULT					CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap);
	IDWriteTextFormat*		CreateD2DFont(const wchar_t* fontName, float fontSize, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch);
	void					PrintMatrix(const wchar_t* str, D2D_MATRIX_3X2_F& mat, float left, float top);

	void					Clear(const D2D1_COLOR_F& color);

private:

	D2DRenderer();
	~D2DRenderer();

	// 복사 & 대입 연산자 삭제
	D2DRenderer(const D2DRenderer&) = delete;
	D2DRenderer& operator=(const D2DRenderer&) = delete;

	static D2DRenderer* pInstance;

	HWND					mHWnd;						// 렌더타겟을 생성할 윈도우 핸들
	D2D_SIZE_U				mScreenSize;	            // 이건 안쓰는 변수?
	D2D_SIZE_U				mClientSize;				// 렌더타겟의 크기
	
	ID2D1HwndRenderTarget*  m_pRenderTarget;			// D2D 렌더타겟
	ID2D1Factory*			m_pD2DFactory;				// D2D 개체 인터페이스 포인터 변수
	IWICImagingFactory*		m_pWICFactory;				// D2D비트맵 생성을 위한 이미지 처리 인터페이스
	IDWriteFactory*			m_pDWriteFactory;			// TextFormat생성을 위한 팩토리
	IDWriteTextFormat*		m_pDWriteTextFormat;		// 기본 텍스트 출력을 위한 Format
	IDXGIFactory4*			m_pDXGIFactory;				// DXGI팩토리
	IDXGIAdapter3*			m_pDXGIAdapter;				// 비디오카드 정보에 접근 가능한 인터페이스					
	ID2D1SolidColorBrush*	m_pBrush;					// 기본 검정 브러쉬 생성
};