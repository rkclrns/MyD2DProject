#include "../D2DEngine/pch.h"
#include "Bullet.h"
#include "../D2DEngine/SpriteRenderer.h"
#include "../D2DEngine/BoxCollider.h"
#include "../D2DEngine/SceneManager.h"

Bullet::Bullet()
	: GameObject()
{
	sprite->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Coromon", L"../Resource/bullet.png"));
	boxCollider->SetSize(50, 50);
}

Bullet::~Bullet()
{
}

void Bullet::PreUpdate()
{
	__super::PreUpdate();
}

void Bullet::Update()
{
	__super::Update();

	// 이동
	transform->position += mDirection * mSpeed * TimeSystem::GetDeltaTime();

	// 수명 카운트
	mCurrentLife += TimeSystem::GetDeltaTime();
	
	if (mCurrentLife >= mLifeTime)
	{
		this->SetDead(true); // 수명 끝나면 제거
	}
}

void Bullet::PostUpdate()
{
	__super::PostUpdate();
}

void Bullet::PreRender()
{
	__super::PreRender();
}

void Bullet::Render()
{
	__super::Render();
}

void Bullet::PostRender()
{
	__super::PostRender();
}

void Bullet::SetDirection(const Vector2& dir)
{
	mDirection = dir;
	mDirection.Normalize(); // 단위 벡터로 보장
}

void Bullet::SetSpeed(float speed)
{
	mSpeed = speed;
}
