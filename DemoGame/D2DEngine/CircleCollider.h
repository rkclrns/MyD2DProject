#pragma once
#include "Collider.h"

class CircleCollider
	: public Collider
{
public:
	CircleCollider();
	~CircleCollider();

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

private:
	float mRadius;
};

