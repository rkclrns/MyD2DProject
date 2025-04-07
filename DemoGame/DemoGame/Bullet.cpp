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

	// �̵�
	transform->position += mDirection * mSpeed * TimeSystem::GetDeltaTime();

	// ���� ī��Ʈ
	mCurrentLife += TimeSystem::GetDeltaTime();
	
	if (mCurrentLife >= mLifeTime)
	{
		this->SetDead(true); // ���� ������ ����
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
	mDirection.Normalize(); // ���� ���ͷ� ����
}

void Bullet::SetSpeed(float speed)
{
	mSpeed = speed;
}
