#pragma once
#include "Collider.h"

class BoxCollider
	: public Collider
{
public:
	BoxCollider();
	~BoxCollider();

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	void SetSize(const Vector2& size);
	void SetSize(float x, float y);
	Vector2& GetSize();

private:
	Vector2 mSize;
};

