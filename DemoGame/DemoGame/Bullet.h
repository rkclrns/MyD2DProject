#pragma once
#include "..\D2DEngine\GameObject.h"

class Bullet :
    public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	void PreUpdate();
	void Update();
	void PostUpdate();
	void PreRender();
	void Render();
	void PostRender();

	void SetDirection(const Vector2& dir);
	void SetSpeed(float speed);

private:

	Vector2 mDirection{};
	float mSpeed = 500.0f; // �⺻ �ӵ�
	float mLifeTime = 3.0f; // ���� ���� (��)
	float mCurrentLife = 0.0f;

};

