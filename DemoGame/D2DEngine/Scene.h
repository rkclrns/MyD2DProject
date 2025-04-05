#pragma once
#include <string>
#include <vector>
#include "GameObject.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	std::vector<GameObject*> mGameObjects;

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	virtual void OnEnter();
	virtual void OnExit();

	std::wstring GetSceneName() { return mName; }
	void SetSceneName(const std::wstring name) { mName = name; }

	const std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }

	// 템플릿 함수로 GameObject를 생성한다.
	template<typename T>
	T* CreateGameObject(const std::wstring name, eObjectTag tag);

private:
	std::wstring mName;
};

template<typename T>
T* Scene::CreateGameObject(const std::wstring name, eObjectTag tag)
{
	bool bIsBase = std::is_base_of<GameObject, T>::value;
	assert(bIsBase == true);	// GameObject를 상속받은 클래스만 생성할 수 있다.
	T* newObject = new T();
	newObject->SetName(name);
	newObject->SetTag(tag);
	mGameObjects.push_back(newObject);
	return newObject;
}

