#pragma once
#include "GameObject.h"

// ������ ���踦 ��Ÿ���� Ŭ����
// GameObect�� �����.
// GameObectŸ������ ������ ��ü���� �����Ͽ� Update, Render�� ȣ���Ѵ�.
class WorldManager
{
public:

	WorldManager();
	virtual ~WorldManager();

	std::list<GameObject*> m_GameObjects;

	int count;
public:
	void Update(float deltaTime);
	void Render(ID2D1RenderTarget* pRenderTarget);
	void Clear();
	//void SetCullingBound(AABB* pBound) { m_pCullingBound = pBound; }
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
