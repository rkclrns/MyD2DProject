#pragma once
#include "GameObject.h"

class GameObject;

class World
{
private:
	std::string mWorldName;
public:
	std::list<GameObject*> m_GameObjects;

	std::string GetWorldName() { return mWorldName; }
};

