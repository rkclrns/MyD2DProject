#include "../D2DEngine/pch.h"
#include "Bullet.h"
#include "../D2DEngine/SpriteRenderer.h"
#include "../D2DEngine/BoxCollider.h"
#include "../D2DEngine/SceneManager.h"

Bullet::Bullet()
	: GameObject()
{

}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	__super::Initialize();

	sprite = AddComponent<SpriteRenderer>();
	sprite->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Bullet", L"../Resource/bullet.png"));
	boxCollider->SetSize(50, 50);
}

void Bullet::PreUpdate()
{
	__super::PreUpdate();
}

void Bullet::Update()
{
	__super::Update();

	if (boxCollider->IsColliding())
	{
		SetDead(true);
	}
	else
	{
		// 시간 지나면 없어지게
	}

	transform->position += mDirection * mSpeed * TimeSystem::GetDeltaTime();
}

void Bullet::Render()
{
	__super::Render();
}

void Bullet::Destroy()
{
}

void Bullet::SetDirection(const Vector2& dir)
{
	mDirection = dir;
	mDirection = mDirection.Normalize(); // 단위 벡터로 보장
}

void Bullet::SetSpeed(float speed)
{
	mSpeed = speed;
}
