#include "pch.h"
#include "Animation.h"

Animation::Animation()
	: Component(eComponentType::Animator)
{
}

Animation::~Animation()
{
}

void Animation::Initialize()
{
	__super::Initialize();
}

void Animation::Destroy()
{
}

void Animation::Update()
{
}

void Animation::Render()
{
}

void Animation::PlayAnimation(const std::wstring name, bool loop)
{

}

ID2D1Bitmap* Animation::GetCurrentImage()
{
	return nullptr;
}

ID2D1Bitmap* Animation::GetImage(const int index)
{
	return nullptr;
}

int Animation::GetCurrFrame()
{
	return 0;
}

int Animation::GetLastFrame()
{
	return 0;
}

void Animation::SetLoop(const bool IsLoop)
{
}

void Animation::SetFrame(const int frame)
{
}

void Animation::SetAnimation(const int index)
{
}

bool Animation::ChangeAnimation()
{
	return false;
}

bool Animation::IsLoop()
{
	return b_isLoop;
}

bool Animation::IsEnd()
{
	return b_isEnd;
}

bool Animation::LoadAnimation()
{
	return false;
}

Animation* Animation::FindAnimation(const std::wstring name)
{
	return nullptr;
}

void Animation::AddFrame()
{
}
