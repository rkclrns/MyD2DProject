#include "DemoGame.h"

void DemoGame::Initialize(HINSTANCE hInstance)
{
	__super::Initialize(hInstance);
}

void DemoGame::Run()
{
	__super::Run();
}

void DemoGame::UnInitialize()
{
	__super::UnInitialize();
}

void DemoGame::Update()
{
	__super::Update();
}

void DemoGame::Render(ID2D1RenderTarget* pRenderTarget)
{
	pRenderTarget->BeginDraw();

	pRenderTarget->EndDraw();
}
