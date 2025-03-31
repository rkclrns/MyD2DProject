#pragma once
#include "Component.h"

struct FrameInfo
{
	ID2D1Bitmap* pBitmap = nullptr;		// 사용할 이미지
	D2D1_RECT_F source = { 0, };		// 출력할 이미지 영역
	D2D_VECTOR_2F center = { 0, };		// 출력할 이미지 중앙
	float duration = 0.1f;				// 해당 이미지 재생 시간
};

struct AnimationInfo
{
	std::vector<FrameInfo> frames;	// 프레임 모음
	std::wstring filePath;			// 애니메이션 경로
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