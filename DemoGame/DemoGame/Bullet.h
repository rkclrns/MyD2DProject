#pragma once
#include "..\D2DEngine\GameObject.h"

class Bullet :
    public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	void Initialize();
	void PreUpdate();
	void Update();
	void Render();
	void Destroy();

	void SetDirection(const Vector2& dir);
	void SetSpeed(float speed);

private:
	SpriteRenderer* sprite = nullptr;
	Vector2 mDirection{};
	float mSpeed = 50000.0f;	// 기본 속도
	float mTimer = 0.0f;		// 총 경과 시간
	float mLifeTimer = 3.0f;	// 3초 후 삭제
};

