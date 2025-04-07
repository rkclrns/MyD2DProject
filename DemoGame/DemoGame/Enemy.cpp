#include "../D2DEngine/pch.h"
#include "Enemy.h"
#include "Bullet.h"
#include "../D2DEngine/SpriteRenderer.h"
#include "../D2DEngine/BoxCollider.h"
#include "../D2DEngine/SceneManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	__super::Initialize();

	transform->SetPosition(Vector2(100.0f, 100.0f));

	m_pSprite = AddComponent<SpriteRenderer>();
	m_pSprite->SetSprite(ResourceManager::GetInstance()->
		Find<Sprite>(L"Kuramon"));

	transform->SetPivot(Vector2(50, 50));
	boxCollider->SetSize(100, 100);
}

void Enemy::PreUpdate()
{
	__super::PreUpdate();
}

void Enemy::Update()
{
	__super::Update();
}

void Enemy::Render()
{
	__super::Render();
}

void Enemy::Destroy()
{
	__super::Destroy();
}
