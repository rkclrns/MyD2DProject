#pragma once
#include "Collider.h"

class CircleCollider
	: public Collider
{
public:
	CircleCollider();
	~CircleCollider();

	void Initialize();
	void PreUpdate();
	void Update();
	void PostUpdate();
	void PreRender();
	void Render();
	void PostRender();

	bool isCollide(Collider* other);
	bool isCollide(const Vector2& point);

private:
	float mRadius;
};

