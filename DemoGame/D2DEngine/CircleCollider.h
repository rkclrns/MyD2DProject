#pragma once
#include "Collider.h"

class CircleCollider
	: public Collider
{
public:
	CircleCollider();
	~CircleCollider();

	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	bool isCollide(Collider* other);
	bool isCollide(const Vector2& point);

private:
	float mRadius;
};

