#include "pch.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"

GameObject::GameObject()
{
	transform = AddComponent<Transform>();
	boxCollider = AddComponent<BoxCollider>();
	sprite = AddComponent<SpriteRenderer>();
	boxCollider->transform = this->transform;
}

GameObject::~GameObject()
{

}

void GameObject::PreUpdate()
{
	for (auto* e : mComponents)
	{
		if(e->GetComponentState() == eComponentState::ACTIVE)
			e->PreUpdate();
	}
}

void GameObject::Update()
{
	for (auto* e : mComponents)
	{
		if (e->GetComponentState() == eComponentState::ACTIVE)
			e->Update();
	}
}

void GameObject::PostUpdate()
{
	for (auto* e : mComponents)
	{
		if (e->GetComponentState() == eComponentState::ACTIVE)
			e->PostUpdate();
	}
}

void GameObject::PreRender()
{
	for (auto* e : mComponents)
	{
		if (e->GetComponentState() == eComponentState::ACTIVE)
			e->PreRender();
	}
}

void GameObject::Render()
{
	for (auto* e : mComponents)
	{
		if (e->GetComponentState() == eComponentState::ACTIVE)
			e->Render();
	}
}

void GameObject::PostRender()
{
	for (auto* e : mComponents)
	{
		if (e->GetComponentState() == eComponentState::ACTIVE)
			e->PostRender();
	}
}
