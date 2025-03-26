#pragma once
#include "pch.h"
#include "D2DRenderer.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class WinApp
{
public:
	WinApp();
	virtual ~WinApp();

	static D2DRenderer* d2d;
	static ResourceManager* resource;

	virtual void Initialize(HINSTANCE hInstance);
	virtual void Run();
	virtual void UnInitialize();
	virtual void Update();
	virtual void Render();

private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	int m_width;
	int m_height;

	void WindowInitialize();
	static void PlaceInCenterOfScreen(HWND window, DWORD style, DWORD exStyle);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};