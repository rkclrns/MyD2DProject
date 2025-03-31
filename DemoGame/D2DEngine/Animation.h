#pragma once
#include "Component.h"

struct FrameInfo
{
	ID2D1Bitmap* pBitmap = nullptr;		// ����� �̹���
	D2D1_RECT_F source = { 0, };		// ����� �̹��� ����
	D2D_VECTOR_2F center = { 0, };		// ����� �̹��� �߾�
	float duration = 0.1f;				// �ش� �̹��� ��� �ð�
};

struct AnimationInfo
{
	std::vector<FrameInfo> frames;	// ������ ����
	std::wstring filePath;			// �ִϸ��̼� ���
};

class Animation
	: public Component
{
public:
	Animation();
	~Animation();

	void Update() override;
	void Render() override;

	void PlayAnimation(const std::wstring name, bool loop = true);

	ID2D1Bitmap* GetCurrentImage();
	ID2D1Bitmap* GetImage(const int index);
	int GetCurrFrame();
	int GetLastFrame();

	void SetLoop(const bool IsLoop);
	void SetFrame(const int frame);
	void SetAnimation(const int index);

	bool ChangeAnimation();
	bool LoadAnimation();
	Animation* FindAnimation(const std::wstring name);

	bool IsLoop();
	bool IsEnd();
	void AddFrame();

private:
	AnimationInfo mAnimationInfo;

	float mCurrFrame = 0.f;
	int mCurrIndex = 0;
	bool b_isEnd = false;
	bool b_isLoop = false;
};