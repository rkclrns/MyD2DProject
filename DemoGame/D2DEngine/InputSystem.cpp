#include "pch.h"

std::vector<InputSystem::Key> InputSystem::mKeys = {};

int ASCII[(UINT)eKeyCode::SIZE] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	VK_SPACE, VK_ESCAPE,
};

void InputSystem::Initialize()
{
	// 초기화 작업

	for (size_t i = 0; i < (UINT)eKeyCode::SIZE; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.state = eKeyState::NONE;
		key.keyCode = (eKeyCode)i;

		mKeys.push_back(key);
	}
}

void InputSystem::Update()
{
	for (size_t i = 0; i < mKeys.size(); i ++)
	{
		// 키가 눌렸는가?
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			// 이전 프레임에서 눌려있었음
			if (mKeys[i].bPressed == true)
			{
				// PRESSED 상태
				mKeys[i].state = eKeyState::PRESSED;
			}
			else // 이전 프레임도 안눌려있음
			{
				// DOWN 상태
				mKeys[i].state = eKeyState::DOWN;
			}

			// 키가 눌려있다고 상태를 바꿔준다
			mKeys[i].bPressed = true;
		}
		else // 키가 안눌렸다
		{
			// 이전 프레임에서 눌려있었다
			if (mKeys[i].bPressed == true)
			{
				// UP 상태
				mKeys[i].state = eKeyState::UP;
			}
			else // 이전 프레임도 안눌려있었다
			{
				// 아무상태도 아님
				mKeys[i].state = eKeyState::NONE;
			}

			// 키가 안눌려있다고 상태를 바꿔준다
			mKeys[i].bPressed = false;
		}
	}
}
