#pragma once
#include "Transform.h"

enum class eObjectState
{
	ACTIVE,
	PASSIVE,
};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	virtual void PreRender();
	virtual void Render();
	virtual void PostRender();

	Transform* transform;

	void SetState(eObjectState eState) { m_state = eState; }
	eObjectState GetState() { return m_state; }

	template <typename T>
	T* GetComponent()
	{
		bool bIsBase = std::is_base_of<Component, T>::value;
		assert(bIsBase == true);	// Component�� ��� ���� Ŭ������ �ҷ����� ����
		
		T* component = nullptr;

		for (auto* e : m_components)
		{
			if (typeid(e).name() == typeid(T).name)
				component = e;
		}

		assert(component != nullptr);	// ã�� ���ߴٸ� ��������ֱ�
		return component;
	};

	template <typename T>
	T* AddComponent()
	{
		bool bIsBase = std::is_base_of<Component, T>::value;
		assert(bIsBase == true);	// Component�� ��� ���� Ŭ������ ���� ����

		T* newCompenent = new T();
		newCompenent->SetOwner(this);

		m_components.pop_back(newCompenent);

		return newCompenent;
	};

	std::vector<Component*> m_components;

private:
	eObjectState m_state = eObjectState::ACTIVE;
};