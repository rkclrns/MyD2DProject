#include "pch.h"
#include "Scene.h"

Scene::Scene()
	: m_GameObjects{}
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
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreUpdate();
		}
	}
}

void Scene::Update()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Update();
		}
	}
}

void Scene::PostUpdate()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostUpdate();
		}
	}
}

void Scene::PreRender()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreRender();
		}
	}
}

void Scene::Render()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Render();
		}
	}
}

void Scene::PostRender()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostRender();
		}
	}
}
