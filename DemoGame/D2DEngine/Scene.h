#pragma once
#include "GameObject.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	std::list<GameObject*> m_GameObjects;

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	std::wstring GetSceneName() { return m_Name; }
	void SetSceneName(const std::wstring name) { m_Name = name; }

	// 템플릿 함수로 GameObject를 생성한다.
	template<typename T>
	T* CreateGameObject();

private:
	std::wstring m_Name;
};

template<typename T>
T* Scene::CreateGameObject()
{
	bool bIsBase = std::is_base_of<GameObject, T>::value;
	assert(bIsBase == true);	// GameObject를 상속받은 클래스만 생성할 수 있다.
	T* newObject = new T();
	m_GameObjects.push_back(newObject);
	return newObject;
}

