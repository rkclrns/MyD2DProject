#include "pch.h"
#include "SceneManager.h"
#include "D2DRenderer.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

std::map<const std::wstring, Scene*> SceneManager::m_Scenes = {};
Scene* SceneManager::m_activeScene = nullptr;

void SceneManager::ChangeWorld(std::wstring sceneName)
{
	for (auto& e : m_Scenes)
	{
		if (e.second->GetSceneName() == sceneName)
		{
			m_activeScene = e.second;
		}
	}
}

Scene* SceneManager::FindScene(const std::wstring& name)
{
	Scene* scene = m_Scenes.find(L"name")->second;
	assert(scene != nullptr);

	return scene;
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
