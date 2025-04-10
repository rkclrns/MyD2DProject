#pragma once
#include "..\D2DEngine\GameObject.h"

class LineRenderer;
class SpriteRenderer;
class Player :
    public GameObject
{
public:
	Player();
	virtual ~Player();

	void Initialize();
	void PreUpdate();
	void Update();
	void Render();
	void Destroy();

public:
	void BulletShot(Vector2 dir);

private:
	SpriteRenderer* m_pSprite = nullptr;
	LineRenderer* m_pLineRenderer = nullptr;
	float mAngleDeg = 0.0f; // 도(degree) 단위 = 0.f; // 조준 각도 (라디안)
	float mRotationSpeed = 100.f; // 돌아가는 속도
	float mRadius = 300.f;	// 반지름
};