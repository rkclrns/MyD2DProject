#pragma once
#include "GameObject.h"

class GameObject;

class World
{
private:
	std::string mWorldName;
public:
	std::list<GameObject*> m_GameObjects;

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	std::string GetWorldName() { return mWorldName; }

	// ���ø� �Լ��� GameObject�� �����Ѵ�.
	template<typename T>
	T* CreateGameObject()
	{
		bool bIsBase = std::is_base_of<GameObject, T>::value;
		assert(bIsBase == true);	// GameObject�� ��ӹ��� Ŭ������ ������ �� �ִ�.
		T* newObject = new T();
		m_GameObjects.push_back(newObject);
		return newObject;
	}
};

