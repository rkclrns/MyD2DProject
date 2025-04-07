#include "pch.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Initialize()
{
	transform = AddComponent<Transform>();
	boxCollider = AddComponent<BoxCollider>();
	boxCollider->transform = this->transform;

	int size = mComponents.size();

	for (int i = 0; i < size; i++)
	{
		if (mComponents[i]->GetComponentState() == eComponentState::ACTIVE)
		{
			mComponents[i]->Initialize();
		}
	}
}

void GameObject::PreUpdate()
{
	int size = mComponents.size();

	for (int i = 0; i < size; i++)
	{
		if (mComponents[i]->GetComponentState() == eComponentState::ACTIVE)
		{
			mComponents[i]->PreUpdate();
		}
	}
}

void GameObject::Update()
{
	int size = mComponents.size();

	for (int i = 0; i < size; i++)
	{
		if (mComponents[i]->GetComponentState() == eComponentState::ACTIVE)
		{
			mComponents[i]->Update();
		}
	}
}

void GameObject::Render()
{
	int size = mComponents.size();

	for (int i = 0; i < size; i++)
	{
		if (mComponents[i]->GetComponentState() == eComponentState::ACTIVE)
		{
			mComponents[i]->Render();
		}
	}
}

void GameObject::Destroy()
{
	int size = mComponents.size();

	for (int i = 0; i < size; i++)
	{
		if (mComponents[i]->GetComponentState() == eComponentState::ACTIVE)
		{
			mComponents[i]->Destroy();
		}
	}
}
