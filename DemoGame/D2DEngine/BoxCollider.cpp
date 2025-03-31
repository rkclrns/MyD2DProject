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

	D2D1_VECTOR_2F pos = { tr->position.x, tr->position.y };
	D2D1_SIZE_F size = { 10.0f, 10.0f };

	D2DRenderer::GetInstance()->DrawRect(pos, size, D2D1::ColorF(D2D1::ColorF::White), true);
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
