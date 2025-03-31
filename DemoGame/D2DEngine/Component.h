#pragma once

class GameObject;
class Component
{
public:
	Component();
	virtual ~Component();

	GameObject* GetOwner() { return m_pOwner; }
	void SetOwner(GameObject* pOwner) { m_pOwner = pOwner; }

	virtual void PreUpdate() = 0;
	virtual void Update() = 0;
	virtual void PostUpdate() = 0;
	virtual void PreRender() = 0;
	virtual void Render() = 0;
	virtual void PostRender() = 0;

private:
	GameObject* m_pOwner;
};

