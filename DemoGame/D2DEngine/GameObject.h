#pragma once
#include "Transform.h"
#include <vector>
#include <assert.h>

enum class eObjectState
{
	ACTIVE,
	PASSIVE,
};

enum class eObjectTag
{
	NONE,
	PLAYER,
	BULLET,
	ENEMY,
	UI,
	SOUND,
};

class SpriteRenderer;
class BoxCollider;
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

	std::wstring GetName() { return mName; }
	void SetName(const std::wstring name) { mName = name; }

	eObjectTag GetTag() { return mTag; }
	void SetTag(eObjectTag tag) { mTag = tag; }

	Transform* transform = nullptr;
	SpriteRenderer* sprite = nullptr;
	BoxCollider* boxCollider = nullptr;

	void SetState(eObjectState eState) { mState = eState; }
	eObjectState GetState() { return mState; }

	void SetDead(bool isDead = true) { bIsDead = isDead; }
	bool IsDead() const { return bIsDead; }

	template <typename T>
	T* GetComponent();

	template <typename T>
	T* AddComponent();


private:
	std::wstring mName;
	eObjectTag mTag;
	std::vector<Component*> mComponents;
	eObjectState mState = eObjectState::ACTIVE;
	bool bIsDead = false;
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

	//assert(component != nullptr);	// 찾지 못했다면 에러띄워주기
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