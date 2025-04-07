#include "..\D2DEngine\pch.h"
#include "PlayScene.h"
#include "..\D2DEngine\SpriteRenderer.h"
#include "..\D2DEngine\BoxCollider.h"
#include "..\D2DEngine\LineRenderer.h"
#include "Player.h"

void PlayScene::Initialize()
{
	bg = CreateGameObject<GameObject>(L"Background", eObjectTag::UI);
	bg->sprite->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Background", L"../Resource/BG.jpg"));
	bg->transform->SetPivot(bg->sprite->GetSprite()->GetCenter());
	bg->boxCollider->SetComponentState(eComponentState::PASSIVE);

	coromon = CreateGameObject<Player>(L"Coromon", eObjectTag::PLAYER);

	ResourceManager::GetInstance()->
		Load<Sprite>(L"Kuramon", L"../Resource/kuramon.png");

	map.resize(5);

	for (size_t i = 0; i < 5; i++)
	{
		map[i].resize(18);
	
		for (size_t j = 0; j < 18; j++)
		{
			GameObject* kuramon = CreateGameObject<GameObject>(L"Enemy", eObjectTag::ENEMY);
			
			kuramon->transform->SetPosition(Vector2(j * 100.0f, i * 100.0f));
			if (i % 2 != 0)
				kuramon->transform->position.x += 100;

			kuramon->sprite->SetSprite(ResourceManager::GetInstance()->
				Find<Sprite>(L"Kuramon"));

			kuramon->transform->SetPivot(Vector2(50, 50));
			kuramon->boxCollider->SetSize(100, 100);
			
			map[i].push_back(kuramon);
		}
	
		map.push_back(map[i]);
	}
}

void PlayScene::PreUpdate()
{
}

void PlayScene::Update()
{
	__super::Update();

	InputUpdate();
}

void PlayScene::PostUpdate()
{
}

void PlayScene::PreRender()
{
}

void PlayScene::Render()
{
	__super::Render();
}

void PlayScene::PostRender()
{

}

void PlayScene::InputUpdate()
{
	
}
