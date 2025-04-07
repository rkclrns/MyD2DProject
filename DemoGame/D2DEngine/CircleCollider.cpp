#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	mType = eColliderType::CIRCLE;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Initialize()
{
}

void CircleCollider::PreUpdate()
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render()
{
}

void CircleCollider::Destroy()
{
}

bool CircleCollider::isCollide(Collider* other)
{
	return false;
}

bool CircleCollider::isCollide(const Vector2& point)
{
	return false;
}
