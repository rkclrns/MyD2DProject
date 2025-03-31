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

void SceneManager::ChangeWorld(std::wstring name)
{
	std::map<std::wstring, Scene*>::iterator itr = m_Scenes.find(name);

	if (itr == m_Scenes.end())
		return;

	m_activeScene = itr->second;
}

Scene* SceneManager::LoadScene(const std::wstring& name)
{
	std::map<std::wstring, Scene*>::iterator itr = m_Scenes.find(name);

	if (itr == m_Scenes.end())
		return nullptr;

	m_activeScene = itr->second;

	return itr->second;
}

Scene* SceneManager::FindScene(const std::wstring& name)
{
	std::map<std::wstring, Scene*>::iterator itr = m_Scenes.find(name);

	if (itr == m_Scenes.end())
		return nullptr;

	return itr->second;
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
