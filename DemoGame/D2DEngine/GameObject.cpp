#include "pch.h"
#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::~GameObject()
{

}

void GameObject::PreUpdate()
{
	for (auto* e : mComponents)
	{
		e->PreUpdate();
	}
}

void GameObject::Update()
{
	for (auto* e : mComponents)
	{
		e->Update();
	}
}

void GameObject::PostUpdate()
{
	for (auto* e : mComponents)
	{
		e->PostUpdate();
	}
}

void GameObject::PreRender()
{
	for (auto* e : mComponents)
	{
		e->PreRender();
	}
}

void GameObject::Render()
{
	for (auto* e : mComponents)
	{
		e->Render();
	}
}

void GameObject::PostRender()
{
	for (auto* e : mComponents)
	{
		e->PostRender();
	}
}
