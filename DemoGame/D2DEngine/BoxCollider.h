#pragma once
#include "Collider.h"

class BoxCollider
	: public Collider
{
public:
	BoxCollider();
	~BoxCollider();

	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	bool isCollide(Collider* other);
	bool isCollide(const Vector2& point);

	void SetSize(const Vector2& size);
	void SetSize(float x, float y);
	Vector2& GetSize();
	D2D1_RECT_F GetColliderRect();

private:
	Vector2 mSize;
};

