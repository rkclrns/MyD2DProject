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
	// �ʱ�ȭ �۾�

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
		// Ű�� ���ȴ°�?
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			// ���� �����ӿ��� �����־���
			if (mKeys[i].bPressed == true)
			{
				// PRESSED ����
				mKeys[i].state = eKeyState::PRESSED;
			}
			else // ���� �����ӵ� �ȴ�������
			{
				// DOWN ����
				mKeys[i].state = eKeyState::DOWN;
			}

			// Ű�� �����ִٰ� ���¸� �ٲ��ش�
			mKeys[i].bPressed = true;
		}
		else // Ű�� �ȴ��ȴ�
		{
			// ���� �����ӿ��� �����־���
			if (mKeys[i].bPressed == true)
			{
				// UP ����
				mKeys[i].state = eKeyState::UP;
			}
			else // ���� �����ӵ� �ȴ����־���
			{
				// �ƹ����µ� �ƴ�
				mKeys[i].state = eKeyState::NONE;
			}

			// Ű�� �ȴ����ִٰ� ���¸� �ٲ��ش�
			mKeys[i].bPressed = false;
		}
	}
}
