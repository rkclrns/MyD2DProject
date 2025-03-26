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

	// 키를 누를 때만 반환
	static bool GetKeyDown(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::DOWN; }
	// 키를 누르는 시간 만큼 반환
	static bool GetKeyPressed(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::PRESSED; }
	// 키를 뗄 때만 반환
	static bool GetKeyUp(eKeyCode keyCode) { return mKeys[(UINT)keyCode].state == eKeyState::UP; }

	static void Initialize();
	static void Update();

private:
	//eKeyState mState = eKeyState::UP;
	static std::vector<Key> mKeys;

};

