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

void BoxCollider::Render()
{
	// 디버그일때만 그리기!!!!

	if(!bIsCollid)
		D2DRenderer::GetInstance()->DrawRect(GetColliderRect(), D2D1::ColorF(D2D1::ColorF::Green), false);
	else
		D2DRenderer::GetInstance()->DrawRect(GetColliderRect(), D2D1::ColorF(D2D1::ColorF::Red), false);
}

void BoxCollider::Destroy()
{
}

bool BoxCollider::isCollide(Collider* other)
{
	BoxCollider* otherBox = static_cast<BoxCollider*>(other);

	auto rectA = GetColliderRect();
	auto rectB = otherBox->GetColliderRect();

	return !(rectA.right < rectB.left ||
		rectA.left > rectB.right ||
		rectA.bottom < rectB.top ||
		rectA.top > rectB.bottom);
}

bool BoxCollider::isCollide(const Vector2& point)
{
	auto rect = GetColliderRect();

	return point.x >= rect.left && point.x <= rect.right &&
		point.y >= rect.top && point.y <= rect.bottom;
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
