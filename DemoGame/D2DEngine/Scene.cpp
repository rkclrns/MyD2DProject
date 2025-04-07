#include "pch.h"
#include "Scene.h"

Scene::Scene()
	: mGameObjects{}
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{

}

void Scene::PreUpdate()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreUpdate();
		}
	}
}

void Scene::Update()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Update();
		}
	}
}

void Scene::PostUpdate()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostUpdate();
		}
	}

	// 죽은 오브젝트 제거
	mGameObjects.erase(
		std::remove_if(mGameObjects.begin(), mGameObjects.end(),
			[](GameObject* obj)
			{
				if (obj->IsDead())
				{
					delete obj;  // 메모리 해제
					return true; // 리스트에서 제거
				}
				return false;
			}),
		mGameObjects.end());
}

void Scene::PreRender()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreRender();
		}
	}
}

void Scene::Render()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Render();
		}
	}
}

void Scene::PostRender()
{
	for (auto* e : mGameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostRender();
		}
	}
}

void Scene::OnEnter()
{
}

void Scene::OnExit()
{
}
