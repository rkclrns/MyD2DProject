#include "pch.h"
#include "WorldManager.h"
#include "D2DRenderer.h"

WorldManager::WorldManager()
{

}

WorldManager::~WorldManager()
{

}

void WorldManager::ChangeWorld(std::string worldName)
{
	for (auto& e : m_WorldList)
	{
		if (e->GetWorldName() == worldName)
		{
			m_currWorld = e;
		}
	}
}

void WorldManager::Update(float deltaTime)
{
	
}

void WorldManager::Render(ID2D1RenderTarget* pRenderTarget)
{

}

void WorldManager::Clear()
{

}
