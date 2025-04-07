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
	int size = mGameObjects.size();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i]->GetState() == eObjectState::ACTIVE)
		{
			mGameObjects[i]->Initialize();
		}
	}
}

void Scene::PreUpdate()
{
	int size = mGameObjects.size();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i]->GetState() == eObjectState::ACTIVE)
		{
			mGameObjects[i]->PreUpdate();
		}
	}
}

void Scene::Update()
{
	int size = mGameObjects.size();
	
	Release();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i]->GetState() == eObjectState::ACTIVE)
		{
			mGameObjects[i]->Update();
		}
	}
}

void Scene::Render()
{
	int size = mGameObjects.size();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i]->GetState() == eObjectState::ACTIVE)
		{
			mGameObjects[i]->Render();
		}
	}
}

void Scene::Release()
{
	// 죽은 오브젝트 제거
	int size = mGameObjects.size();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i] && mGameObjects[i]->IsDead()) {
			delete mGameObjects[i];
			mGameObjects[i] = nullptr;
		}
	}
}

void Scene::UnInitialize()
{
	int size = mGameObjects.size();

	for (int i = 0; i < size; i++)
	{
		if (!mGameObjects[i])
			continue;

		if (mGameObjects[i]->GetState() == eObjectState::ACTIVE)
		{
			mGameObjects[i]->Destroy();
		}
	}
}

void Scene::OnEnter()
{
}

void Scene::OnExit()
{
}
