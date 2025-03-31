#pragma once
#include "pch.h"
#include "GameObject.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	std::list<GameObject*> mGameObjects;

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

	// ���ø� �Լ��� GameObject�� �����Ѵ�.
	template<typename T>
	T* CreateGameObject();

private:
	std::wstring mName;
};

template<typename T>
T* Scene::CreateGameObject()
{
	bool bIsBase = std::is_base_of<GameObject, T>::value;
	assert(bIsBase == true);	// GameObject�� ��ӹ��� Ŭ������ ������ �� �ִ�.
	T* newObject = new T();
	mGameObjects.push_back(newObject);
	return newObject;
}

