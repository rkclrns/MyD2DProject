#pragma once
#include "Component.h"
#include "Vector2.h"

class Collider
	: public Component
{
public:

	Collider();
	~Collider();

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	void SetOffset(const Vector2& offset);
	void SetOffset(float x, float y);
	Vector2& GetOffset();

protected:
	Vector2 mOffset;
};

