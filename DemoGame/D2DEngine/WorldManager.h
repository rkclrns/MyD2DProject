#pragma once
#include "World.h"

// ������ ���踦 ��Ÿ���� Ŭ����
// GameObect�� �����.
// GameObectŸ������ ������ ��ü���� �����Ͽ� Update, Render�� ȣ���Ѵ�.
class WorldManager
{
public:

	WorldManager();
	virtual ~WorldManager();

	std::list<World*> m_WorldList;

	World* m_currWorld = nullptr;

public:
	void ChangeWorld(std::string worldName);

	void Update(float deltaTime);
	void Render(ID2D1RenderTarget* pRenderTarget);
	void Clear();
	
	// ���ø� �Լ��� GameObject�� �����Ѵ�.
	template<typename T>
	T* CreateGameObject()
	{
		bool bIsBase = std::is_base_of<GameObject, T>::value;
		assert(bIsBase == true);	// GameObject�� ��ӹ��� Ŭ������ ������ �� �ִ�.
		T* newObject = new T();
		newObject->SetOwner(this);
		m_GameObjects.push_back(newObject);
		return newObject;
	}
};
