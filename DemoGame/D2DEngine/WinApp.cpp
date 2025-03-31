#include "WinApp.h"

#define SCREEN_START_LEFT 0
#define SCREEN_START_TOP 0
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

WinApp::WinApp()
{
	// 생성
	d2d = new D2DRenderer;
	resource = new ResourceManager;
}

WinApp::~WinApp()
{

}

// 스태틱 초기화
D2DRenderer* WinApp::d2d = nullptr;
ResourceManager* WinApp::resource = nullptr;
 
void WinApp::Initialize(HINSTANCE hInstance)
{
	mHInstance = hInstance;

	WindowInitialize();
	d2d->Initialize(mHWnd);

	SceneManager::Initialize();
	TimeSystem::Initialize();
	InputSystem::Initialize();
}

void WinApp::Run()
{
	MSG msg;
	// 기본 메시지 루프입니다:
	while (TRUE)
	{
		// 메세지 유무 확인
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// 종료 메세지라면 그만두기
			if (msg.message == WM_QUIT)
				break;

			//윈도우 메시지 처리 
			TranslateMessage(&msg);			// 키입력관련 메시지 변환  WM_KEYDOWN -> WM_CHAR
			DispatchMessage(&msg);			// 메세지 전달
		}
		else
		{
			Update();						// 게임 로직 업데이트
			Render();	// 게임 화면 렌더링
		}
	}
}

void WinApp::UnInitialize()
{
	// d2d 삭제
	d2d->Uninitialize();
	// COM 사용 끝 (사용은 d2d에서 함)
	CoUninitialize();
}

void WinApp::Render()
{
	SceneManager::Render();
}

void WinApp::Update()
{
	SceneManager::Update();
	TimeSystem::Update();
	InputSystem::Update();
}

void WinApp::WindowInitialize()
{
	const TCHAR* appName = TEXT("가글가글");

	// Registering the Window Class
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;										// 창 가로나 세로 변경 시 다시 그리기
	wndClass.lpfnWndProc = WndProc;													// 윈도우 메세지 받을 때 호출될 함수 지정
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = mHInstance;												// 인스턴스 저장
	wndClass.hIcon = LoadIcon(mHInstance, IDI_APPLICATION);						// 아이콘 관련 설정
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);									// 커서 관련 설정
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));		// 윈도우 배경 설정
	wndClass.lpszMenuName = NULL;													// 메뉴 없음
	wndClass.lpszClassName = appName;												// 윈도우 이름 설정

	RegisterClass(&wndClass);														// 클래스를 OS에 등록함

	// Creating the Window
	// 크기 설정
	RECT rect{ SCREEN_START_LEFT, SCREEN_START_TOP,
	SCREEN_START_LEFT + SCREEN_WIDTH, SCREEN_START_TOP + SCREEN_HEIGHT };
	
	// 창의 실제 크기를 계산하는 역할
	// 매개변수 (변환할 Rect 구조체, 창 스타일, 메뉴 포함 여부)
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	// 조정된 크기에서 다시 연산
	mWidth = rect.right - rect.left;
	mHeight = rect.bottom - rect.top;

	// 윈도우 생성
	// 윈도우 클래스 명, 창 제목, 창스타일, 창의 시작좌표,
	// 조정된 창 크기, 부모윈도우와 메뉴 없음, 실행 인스턴스, 추가 매개변수 없음
	mHWnd = CreateWindow(appName, appName, WS_OVERLAPPED | WS_SYSMENU,
		SCREEN_START_LEFT, SCREEN_START_TOP, mWidth, mHeight, NULL, NULL, mHInstance, NULL);

	// 
	ShowWindow(mHWnd, SW_SHOWNORMAL);
	UpdateWindow(mHWnd);
}

void WinApp::PlaceInCenterOfScreen(HWND window, DWORD style, DWORD exStyle)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	RECT clientRect;
	GetClientRect(window, &clientRect);

	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.bottom - clientRect.top;

	SetWindowPos(window, NULL,
		screenWidth / 2 - clientWidth / 2,
		screenHeight / 2 - clientHeight / 2,
		clientWidth, clientHeight, 0
	);
}

LRESULT CALLBACK WinApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		// 윈도우 처음 생성 시 실행되는 곳
		PlaceInCenterOfScreen(hWnd, WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
	}
	break;
	case WM_DESTROY:
		// 윈도우 종료시 실행되는 곳
		PostQuitMessage(0);
		break;
	default:
		// 나머지는 기본 처리를 한다
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}