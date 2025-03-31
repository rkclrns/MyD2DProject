#include "pch.h"
#include "SceneManager.h"
#include "D2DRenderer.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

std::map<const std::wstring, Scene*> SceneManager::mScenes = {};
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::ChangeWorld(std::wstring name)
{
	if (mActiveScene)
		mActiveScene->OnExit();

	std::map<std::wstring, Scene*>::iterator itr = mScenes.find(name);

	if (itr == mScenes.end())
		return;

	mActiveScene = itr->second;
	mActiveScene->OnEnter();
}

Scene* SceneManager::FindScene(const std::wstring& name)
{
	std::map<std::wstring, Scene*>::iterator itr = mScenes.find(name);

	if (itr == mScenes.end())
		return nullptr;

	return itr->second;
}

void SceneManager::Initialize()
{
}

void SceneManager::PreUpdate()
{
	if (!mActiveScene)
		return;

	mActiveScene->PreUpdate();
}

void SceneManager::Update()
{
	if (!mActiveScene)
		return;

	mActiveScene->Update();
}

void SceneManager::PostUpdate()
{
	if (!mActiveScene)
		return;

	mActiveScene->PostUpdate();
}

void SceneManager::PreRender()
{
	if (!mActiveScene)
		return;

	mActiveScene->PreRender();
}

void SceneManager::Render()
{
	if (!mActiveScene)
		return;

	mActiveScene->Render();
}

void SceneManager::PostRender()
{
	if (!mActiveScene)
		return;

	mActiveScene->PostRender();
}

void SceneManager::Clear()
{

}
