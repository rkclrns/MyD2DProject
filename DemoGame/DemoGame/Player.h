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
	float mAngleDeg = 0.0f; // ��(degree) ���� = 0.f; // ���� ���� (����)
	float mRotationSpeed = 100.f; // ���ư��� �ӵ�
	float mRadius = 300.f;	// ������
};