#include "pch.h"
#include "Component.h"
#include "Transform.h"


GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::PreUpdate()
{
	for (auto* e : m_components)
	{
		e->PreUpdate();
	}
}

void GameObject::Update()
{
	for (auto* e : m_components)
	{
		e->Update();
	}
}

void GameObject::PostUpdate()
{
	for (auto* e : m_components)
	{
		e->PostUpdate();
	}
}

void GameObject::PreRender()
{
	for (auto* e : m_components)
	{
		e->PreRender();
	}
}

void GameObject::Render()
{
	for (auto* e : m_components)
	{
		e->Render();
	}
}

void GameObject::PostRender()
{
	for (auto* e : m_components)
	{
		e->PostRender();
	}
}
