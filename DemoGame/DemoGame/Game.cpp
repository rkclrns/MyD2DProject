#include "Game.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	DemoGame demoGame;

	demoGame.Initialize(hInstance);

	demoGame.Run();

	demoGame.UnInitialize();

	return EXIT_SUCCESS;
}