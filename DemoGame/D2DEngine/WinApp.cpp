#include "WinApp.h"

#define SCREEN_START_LEFT 0
#define SCREEN_START_TOP 0
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

WinApp::WinApp()
{
	// ����
	d2d = new D2DRenderer;
	resource = new ResourceManager;
	world = new WorldManager;
}

WinApp::~WinApp()
{

}

// ����ƽ �ʱ�ȭ
D2DRenderer* WinApp::d2d = nullptr;
ResourceManager* WinApp::resource = nullptr;
WorldManager* WinApp::world = nullptr;
 
void WinApp::Initialize(HINSTANCE hInstance)
{
	m_hInstance = hInstance;

	WindowInitialize();
	d2d->Initialize(m_hWnd);
}

void WinApp::Run()
{
	MSG msg;
	// �⺻ �޽��� �����Դϴ�:
	while (TRUE)
	{
		// �޼��� ���� Ȯ��
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// ���� �޼������ �׸��α�
			if (msg.message == WM_QUIT)
				break;

			//������ �޽��� ó�� 
			TranslateMessage(&msg);			// Ű�Է°��� �޽��� ��ȯ  WM_KEYDOWN -> WM_CHAR
			DispatchMessage(&msg);			// �޼��� ����
		}
		else
		{
			Update();						// ���� ���� ������Ʈ
			Render();	// ���� ȭ�� ������
		}
	}
}

void WinApp::UnInitialize()
{
	// d2d ����
	d2d->Uninitialize();
	// COM ��� �� (����� d2d���� ��)
	CoUninitialize();
}

void WinApp::Render()
{
	
}

void WinApp::Update()
{

}

void WinApp::WindowInitialize()
{
	const TCHAR* appName = TEXT("���۰���");

	// Registering the Window Class
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;										// â ���γ� ���� ���� �� �ٽ� �׸���
	wndClass.lpfnWndProc = WndProc;													// ������ �޼��� ���� �� ȣ��� �Լ� ����
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = m_hInstance;												// �ν��Ͻ� ����
	wndClass.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);						// ������ ���� ����
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);									// Ŀ�� ���� ����
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));		// ������ ��� ����
	wndClass.lpszMenuName = NULL;													// �޴� ����
	wndClass.lpszClassName = appName;												// ������ �̸� ����

	RegisterClass(&wndClass);														// Ŭ������ OS�� �����

	// Creating the Window
	// ũ�� ����
	RECT rect{ SCREEN_START_LEFT, SCREEN_START_TOP,
	SCREEN_START_LEFT + SCREEN_WIDTH, SCREEN_START_TOP + SCREEN_HEIGHT };
	
	// â�� ���� ũ�⸦ ����ϴ� ����
	// �Ű����� (��ȯ�� Rect ����ü, â ��Ÿ��, �޴� ���� ����)
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	// ������ ũ�⿡�� �ٽ� ����
	m_width = rect.right - rect.left;
	m_height = rect.bottom - rect.top;

	// ������ ����
	// ������ Ŭ���� ��, â ����, â��Ÿ��, â�� ������ǥ,
	// ������ â ũ��, �θ�������� �޴� ����, ���� �ν��Ͻ�, �߰� �Ű����� ����
	m_hWnd = CreateWindow(appName, appName, WS_OVERLAPPED | WS_SYSMENU,
		SCREEN_START_LEFT, SCREEN_START_TOP, m_width, m_height, NULL, NULL, m_hInstance, NULL);

	// 
	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);
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
		// ������ ó�� ���� �� ����Ǵ� ��
		PlaceInCenterOfScreen(hWnd, WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
	}
	break;
	case WM_DESTROY:
		// ������ ����� ����Ǵ� ��
		PostQuitMessage(0);
		break;
	default:
		// �������� �⺻ ó���� �Ѵ�
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}