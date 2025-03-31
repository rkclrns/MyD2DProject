#pragma once

class GameObject;

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
	Camera,
	End,
};

class Component
{
public:
	Component(eComponentType type);
	virtual ~Component();

	GameObject* GetOwner() { return m_pOwner; }
	void SetOwner(GameObject* pOwner) { m_pOwner = pOwner; }

	virtual void Initialize();
	virtual void PreUpdate() = 0;
	virtual void Update() = 0;
	virtual void PostUpdate() = 0;
	virtual void PreRender() = 0;
	virtual void Render() = 0;
	virtual void PostRender() = 0;

private:
	GameObject* m_pOwner;
	eComponentType mType;
};

