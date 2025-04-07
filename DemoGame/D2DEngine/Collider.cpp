#include "pch.h"
#include "Collider.h"

Collider::Collider()
	: Component(eComponentType::Collider)
{

}

Collider::~Collider()
{
}

void Collider::Initialize()
{
}

void Collider::PreUpdate()
{
}

void Collider::Update()
{
}

void Collider::Render()
{
}

void Collider::Destroy()
{
}

void Collider::SetOffset(const Vector2& offset)
{
	mOffset = offset;
}

void Collider::SetOffset(float x, float y)
{
	mOffset = Vector2(x, y);
}

Vector2& Collider::GetOffset()
{
	return mOffset;
}

Vector2& Collider::GetPosition()
{
	return mPosition;
}

eColliderType Collider::GetColliderType()
{
	return mType;
}
