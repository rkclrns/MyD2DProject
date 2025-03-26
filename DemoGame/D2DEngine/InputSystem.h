#pragma once

enum class eKeyState
{
	DOWN,
	PRESSED,
	UP,
	NONE,
};

enum class eKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M, 
	LEFT, RIGHT, DOWN, UP,
	SPACE, ESC, 
	SIZE,
};

class InputSystem
{
public:
	struct Key
	{
		eKeyCode keyCode;
		eKeyState state;
		bool bPressed;
	};

	// Ű�� ���� ���� ��ȯ
	static bool GetKeyDown(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::DOWN; }
	// Ű�� ������ �ð� ��ŭ ��ȯ
	static bool GetKeyPressed(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::PRESSED; }
	// Ű�� �� ���� ��ȯ
	static bool GetKeyUp(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::UP; }

	static void Initialize();
	static void Update();

private:
	//eKeyState mState = eKeyState::UP;
	static std::vector<Key> mKeys;

};

