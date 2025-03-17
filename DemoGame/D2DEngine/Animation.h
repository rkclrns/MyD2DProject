#pragma once

struct Frame_INFO
{
	D2D1_RECT_F source;		// 크기
	D2D1_VECTOR_2F center;	// 중심
	float duration;			// 주기
};

struct Animation_INFO
{
	std::string name;				// 애니메이션 이름
	std::vector<Frame_INFO> frames;	// 프레임 모음
};

class AnimationAsset
{
public:
	AnimationAsset() {};
	~AnimationAsset() {};

	std::vector<Animation_INFO> animations;

};

