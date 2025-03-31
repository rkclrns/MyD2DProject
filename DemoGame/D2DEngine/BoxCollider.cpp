#include "pch.h"
#include "BoxCollider.h"
#include "Transform.h"
#include "GameObject.h"

BoxCollider::BoxCollider()
	: Collider()
{
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Initialize()
{
}

void BoxCollider::PreUpdate()
{
}

void BoxCollider::Update()
{
}

void BoxCollider::PostUpdate()
{
}

void BoxCollider::PreRender()
{
}

void BoxCollider::Render()
{
	Transform* tr = GetOwner()->transform;

}

void BoxCollider::PostRender()
{
}

void BoxCollider::SetSize(const Vector2& size)
{
	mSize = size;
}

void BoxCollider::SetSize(float x, float y)
{
	mSize = Vector2(x, y);
}

Vector2& BoxCollider::GetSize()
{
	return mSize;
}
