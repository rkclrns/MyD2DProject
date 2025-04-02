#include "pch.h"
#include "BoxCollider.h"
#include "Transform.h"
#include "GameObject.h"

BoxCollider::BoxCollider()
	: Collider()
{
	mType = eColliderType::BOX;
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
	mPosition = transform->GetWorldPosition();
}

void BoxCollider::PostUpdate()
{
}

void BoxCollider::PreRender()
{
}

void BoxCollider::Render()
{
	D2DRenderer::GetInstance()->DrawRect(GetColliderRect(), D2D1::ColorF(D2D1::ColorF::Red), false);
}

void BoxCollider::PostRender()
{
}

bool BoxCollider::isCollide(Collider* other)
{
	return false;
}

bool BoxCollider::isCollide(const Vector2& point)
{
	return false;
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

D2D1_RECT_F BoxCollider::GetColliderRect()
{
	// 중앙정렬 출력
	//D2D1_RECT_F rect;
	//rect.left = mPosition.x - mSize.x * 0.5f;
	//rect.right = mPosition.x + mSize.x * 0.5f;
	//rect.top = mPosition.y - mSize.y * 0.5f;
	//rect.bottom = mPosition.y + mSize.y * 0.5f;

	// 좌상단 정렬 출력
	D2D1_RECT_F rect{};
	rect.left = mPosition.x;
	rect.top = mPosition.y;
	rect.right = mPosition.x + mSize.x;
	rect.bottom = mPosition.y + mSize.y;

	return rect;
}
