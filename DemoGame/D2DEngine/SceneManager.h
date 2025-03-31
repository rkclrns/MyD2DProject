#pragma once
#include "Scene.h"

// 게임의 세계를 나타내는 클래스
class SceneManager
{
public:

	SceneManager();
	virtual ~SceneManager();

	static std::map<const std::wstring, Scene*> mScenes;
	static Scene* mActiveScene;

public:
	static void ChangeWorld(std::wstring sceneName);
	
	template <typename T>
	static T* CreateScene(const std::wstring& name);
	static Scene* FindScene(const std::wstring& name);

	static void Initialize();
	static void PreUpdate();
	static void Update();
	static void PostUpdate();
	static void PreRender();
	static void Render();
	static void PostRender();
	static void Clear();
};

template <typename T>
T* SceneManager::CreateScene(const std::wstring& name)
{
	bool bIsBase = std::is_base_of<Scene, T>::value;
	assert(bIsBase == true);	// Scene를 상속받은 클래스만 생성할 수 있다.
	T* scene = new T();
	scene->SetSceneName(name);
	scene->Initialize();

	mScenes.insert(std::make_pair(name, scene));

	return scene;
}