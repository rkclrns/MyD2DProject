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

void CircleCollider::PostUpdate()
{
}

void CircleCollider::PreRender()
{
}

void CircleCollider::Render()
{
}

void CircleCollider::PostRender()
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
