#pragma once
#include "Component.h"
#include "Vector2.h"

enum class eColliderType
{
	NONE,
	BOX,
	CIRCLE,
};

class Transform;
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

	bool IsColliding() const { return bIsCollid; }
	void SetColliding(bool val) { bIsCollid = val; }

	virtual bool isCollide(Collider* other) = 0;
	virtual bool isCollide(const Vector2& point) = 0;

	void SetOffset(const Vector2& offset);
	void SetOffset(float x, float y);

	Vector2& GetOffset();
	Vector2& GetPosition();
	eColliderType GetColliderType();

	Transform* transform = nullptr;

protected:
	bool bIsCollid = false;
	eColliderType mType;
	Vector2 mPosition{};
	Vector2 mOffset{};
};

