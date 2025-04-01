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
	Vector2 point = GetOwner()->transform->position + mOffset;

	D2D1_VECTOR_2F pos = { point.x, point.y };

	D2DRenderer::GetInstance()->DrawRect(pos, {mSize.x + mOffset.x, mSize.y + mOffset.y}, D2D1::ColorF(D2D1::ColorF::White), false);
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
