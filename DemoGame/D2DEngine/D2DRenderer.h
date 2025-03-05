#pragma once
#include "pch.h"
#include <d2d1.h>

class D2DRenderer
{
public:

	D2DRenderer();
	~D2DRenderer();

	static D2D1_MATRIX_3X2_F m_cameraTransform;		// ī�޶� ���� �����

	void					Initialize(HWND hWnd);
	void					Uninitialize();

	void					DrawRect(const D2D1_RECT_F& rectPoint, const D2D1_COLOR_F& color, bool rectFill, float alpha = 1.f);
	void					DrawTextW(const wchar_t* text, IDWriteTextFormat*& fontFormat, const D2D1_RECT_F& drawRect, const D2D1_COLOR_F& color, float alpha = 1.f);
	void					DrawLine(const D2D1_POINT_2F startPoint, const D2D1_POINT_2F endPoint, const D2D1_COLOR_F& color, float alpha = 1.f);

	ID2D1Factory*			GetFactory() { return m_pD2DFactory; }
	ID2D1HwndRenderTarget*	GetRenderTarget() { return m_pRenderTarget; }
	size_t					GetUsedVRAM();

	HRESULT					CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap);
	void					PrintMatrix(const wchar_t* str, D2D_MATRIX_3X2_F& mat, float left, float top);

private:

	HWND					m_hWnd;						// ����Ÿ���� ������ ������ �ڵ�
	D2D_SIZE_U				m_ScreenSize;	            // �̰� �Ⱦ��� ����?
	D2D_SIZE_U				m_ClientSize;				// ����Ÿ���� ũ��
	
	ID2D1HwndRenderTarget*  m_pRenderTarget;			// D2D ����Ÿ��
	ID2D1Factory*			m_pD2DFactory;				// D2D ��ü �������̽� ������ ����
	IWICImagingFactory*		m_pWICFactory;				// D2D��Ʈ�� ������ ���� �̹��� ó�� �������̽�
	IDWriteFactory*			m_pDWriteFactory;			// TextFormat������ ���� ���丮
	IDWriteTextFormat*		m_pDWriteTextFormat;		// �⺻ �ؽ�Ʈ ����� ���� Format
	IDXGIFactory4*			m_pDXGIFactory;				// DXGI���丮
	IDXGIAdapter3*			m_pDXGIAdapter;				// ����ī�� ������ ���� ������ �������̽�					
	ID2D1SolidColorBrush*	m_pBrush;					// �⺻ ���� �귯�� ����
};