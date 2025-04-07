#include "..\D2DEngine\pch.h"
#include "PlayScene.h"
#include "..\D2DEngine\SpriteRenderer.h"
#include "..\D2DEngine\BoxCollider.h"
#include "..\D2DEngine\LineRenderer.h"
#include "Player.h"
#include "Enemy.h"

void PlayScene::Initialize()
{
	bg = CreateGameObject<GameObject>(L"Background", eObjectTag::UI);
	bg->AddComponent<SpriteRenderer>()->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Background", L"../Resource/BG.jpg"));
	bg->transform->SetPivot(bg->GetComponent<SpriteRenderer>()->GetSprite()->GetCenter());
	bg->boxCollider->SetComponentState(eComponentState::PASSIVE);

	bg2 = CreateGameObject<GameObject>(L"Background", eObjectTag::UI);
	bg2->AddComponent<SpriteRenderer>()->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Background_2", L"../Resource/BG_2.png"));
	bg2->transform->SetPivot(bg2->GetComponent<SpriteRenderer>()->GetSprite()->GetCenter());
	bg2->boxCollider->SetComponentState(eComponentState::PASSIVE);

	ResourceManager::GetInstance()->
		Load<Sprite>(L"Kuramon", L"../Resource/kuramon.png");

	coromon = CreateGameObject<Player>(L"Coromon", eObjectTag::PLAYER);
	kuramon = CreateGameObject<Enemy>(L"Kuramon", eObjectTag::ENEMY);

}

void PlayScene::PreUpdate()
{
	__super::PreUpdate();
}

void PlayScene::Update()
{
	__super::Update();
}

void PlayScene::Render()
{
	__super::Render();
}