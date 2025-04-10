#pragma once
#include "Transform.h"
#include <vector>
#include <assert.h>

enum class eObjectState
{
	ACTIVE,
	PASSIVE,
};

enum class eObjectTag : int
{
	NONE	= 0,		//		0000
	PLAYER	= 1 << 0,	//		0001
	BULLET	= 1 << 1,	//		0010
	ENEMY	= 1 << 2,	//		0100
	UI		= 1 << 3,	//		1000
	SOUND	= 1 << 4,	//	 1	0000
};

class SpriteRenderer;
class BoxCollider;
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void PreUpdate();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	std::wstring GetName() { return mName; }
	void SetName(const std::wstring name) { mName = name; }

	eObjectTag GetTag() { return mTag; }
	void SetTag(eObjectTag tag) { mTag = tag; }

	Transform* transform = nullptr;
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
	assert(bIsBase == true);	// Component�� ��� ���� Ŭ������ �ҷ����� ����

	for (auto* e : mComponents)
	{
		T* component = dynamic_cast<T*>(e);
		if (component != nullptr)
		{
			return component;  // ã���� �ٷ� ��ȯ
		}
	}

	return nullptr;
	//assert(component != nullptr);	// ã�� ���ߴٸ� ��������ֱ�
	//return component;
};

template <typename T>
T* GameObject::AddComponent()
{
	bool bIsBase = std::is_base_of<Component, T>::value;
	assert(bIsBase == true);	// Component�� ��� ���� Ŭ������ ���� ����

	T* newCompenent = new T();
	newCompenent->SetOwner(this);
	newCompenent->Initialize();

	mComponents.push_back(newCompenent);

	return newCompenent;
};