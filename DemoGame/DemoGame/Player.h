#pragma once
#include "..\D2DEngine\GameObject.h"

class LineRenderer;
class Player :
    public GameObject
{
public:
	Player();
	virtual ~Player();

	void PreUpdate();
	void Update();
	void PostUpdate();
	void PreRender();
	void Render();
	void PostRender();

public:
	void FireBullet();

private:
	LineRenderer* lineRenderer = nullptr;
	float aimAngle = 0.f; // ���� ���� (����)
	float aimLength = 30.f; // ���� ����
};

