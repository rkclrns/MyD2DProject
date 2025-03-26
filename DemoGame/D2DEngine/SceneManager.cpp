#include "pch.h"
#include "SceneManager.h"
#include "D2DRenderer.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

std::list<Scene*> SceneManager::m_SceneList = {};
Scene* SceneManager::m_activeScene = nullptr;

void SceneManager::ChangeWorld(std::wstring sceneName)
{
	for (auto& e : m_SceneList)
	{
		if (e->GetSceneName() == sceneName)
		{
			m_activeScene = e;
		}
	}
}

void SceneManager::Initialize()
{
}

void SceneManager::PreUpdate()
{
	if (!m_activeScene)
		return;

	m_activeScene->PreUpdate();
}

void SceneManager::Update()
{
	if (!m_activeScene)
		return;

	m_activeScene->Update();
}

void SceneManager::PostUpdate()
{
	if (!m_activeScene)
		return;

	m_activeScene->PostUpdate();
}

void SceneManager::PreRender()
{
	if (!m_activeScene)
		return;

	m_activeScene->PreRender();
}

void SceneManager::Render()
{
	if (!m_activeScene)
		return;

	m_activeScene->Render();
}

void SceneManager::PostRender()
{
	if (!m_activeScene)
		return;

	m_activeScene->PostRender();
}

void SceneManager::Clear()
{

}
