#include "..\D2DEngine\pch.h"
#include "PlayScene.h"
#include "..\D2DEngine\SpriteRenderer.h"
#include "..\D2DEngine\BoxCollider.h"
#include "..\D2DEngine\LineRenderer.h"
#include "..\D2DEngine\TextRenderer.h"
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

	text = CreateGameObject<GameObject>(L"score", eObjectTag::UI);
	textRenderer = text->AddComponent<TextRenderer>();

	ResourceManager::GetInstance()->
		Load<Sprite>(L"Kuramon", L"../Resource/kuramon.png");

	coromon = CreateGameObject<Player>(L"Coromon", eObjectTag::PLAYER);
}

void PlayScene::PreUpdate()
{
	__super::PreUpdate();
}

void PlayScene::Update()
{
	__super::Update();

	spawnTimer += TimeSystem::GetDeltaTime();

	textRenderer->SetText(L"잡은 몬스터 수 : " + std::to_wstring(score));

	if (spawnTimer >= spawnInterval)
	{
		spawnTimer = 0.0f;

		// 새로 생성
		Enemy* newKuramon = CreateGameObject<Enemy>(L"Kuramon", eObjectTag::ENEMY);

		// 랜덤 위치 지정
		int x = rand() % 1900;
		int y = rand() % 500;
		newKuramon->transform->SetPosition({ x, y });
	}
}

void PlayScene::Render()
{
	__super::Render();
}