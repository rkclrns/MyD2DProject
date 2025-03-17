#pragma once

struct Frame_INFO
{
	D2D1_RECT_F source;		// ũ��
	D2D1_VECTOR_2F center;	// �߽�
	float duration;			// �ֱ�
};

struct Animation_INFO
{
	std::string name;				// �ִϸ��̼� �̸�
	std::vector<Frame_INFO> frames;	// ������ ����
};

class AnimationAsset
{
public:
	AnimationAsset() {};
	~AnimationAsset() {};

	std::vector<Animation_INFO> animations;

};

