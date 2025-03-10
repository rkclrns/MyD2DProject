#include "pch.h"
#include "World.h"

void World::Initialize()
{

}

void World::PreUpdate()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreUpdate();
		}
	}
}

void World::Update()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Update();
		}
	}
}

void World::PostUpdate()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostUpdate();
		}
	}
}

void World::PreRender()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PreRender();
		}
	}
}

void World::Render()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->Render();
		}
	}
}

void World::PostRender()
{
	for (auto* e : m_GameObjects)
	{
		if (e->GetState() == eObjectState::ACTIVE)
		{
			e->PostRender();
		}
	}
}
