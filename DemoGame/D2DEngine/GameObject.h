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

	void SetState(eObjectState eState) { mState = eState; }
	eObjectState GetState() { return mState; }

	template <typename T>
	T* GetComponent();

	template <typename T>
	T* AddComponent();


private:
	std::vector<Component*> mComponents;
	eObjectState mState = eObjectState::ACTIVE;
};


template <typename T>
T* GameObject::GetComponent()
{
	bool bIsBase = std::is_base_of<Component, T>::value;
	assert(bIsBase == true);	// Component를 상속 받은 클래스만 불러오기 가능

	T* component = nullptr;

	for (auto* e : mComponents)
	{
		if (typeid(e).name() == typeid(T).name)
			component = e;
	}

	assert(component != nullptr);	// 찾지 못했다면 에러띄워주기
	return component;
};

template <typename T>
T* GameObject::AddComponent()
{
	bool bIsBase = std::is_base_of<Component, T>::value;
	assert(bIsBase == true);	// Component를 상속 받은 클래스만 생성 가능

	T* newCompenent = new T();
	newCompenent->SetOwner(this);
	newCompenent->Initialize();

	mComponents.push_back(newCompenent);

	return newCompenent;
};