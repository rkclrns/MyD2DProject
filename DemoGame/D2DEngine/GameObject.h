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
		assert(bIsBase == true);	// Component를 상속 받은 클래스만 불러오기 가능
		
		T* component = nullptr;

		for (auto* e : m_components)
		{
			if (typeid(e).name() == typeid(T).name)
				component = e;
		}

		assert(component != nullptr);	// 찾지 못했다면 에러띄워주기
		return component;
	};

	template <typename T>
	T* AddComponent()
	{
		bool bIsBase = std::is_base_of<Component, T>::value;
		assert(bIsBase == true);	// Component를 상속 받은 클래스만 생성 가능

		T* newCompenent = new T();
		newCompenent->SetOwner(this);

		m_components.pop_back(newCompenent);

		return newCompenent;
	};

	std::vector<Component*> m_components;

private:
	eObjectState m_state = eObjectState::ACTIVE;
};