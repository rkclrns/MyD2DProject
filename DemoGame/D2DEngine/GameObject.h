#pragma once

class Component;
class World;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void Update(float deltaTime);
	void Render(ID2D1RenderTarget* pRenderTarget);

	void AddComponent(Component* pComponent);

private:
	
	std::vector<Component*> m_components;
	//std::vector<GameObject*> m_chideren;
};