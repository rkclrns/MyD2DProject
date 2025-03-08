#pragma once
#include "World.h"

// 게임의 세계를 나타내는 클래스
// GameObect를 만든다.
// GameObect타입으로 생성된 객체들을 관리하여 Update, Render를 호출한다.
class WorldManager
{
public:

	WorldManager();
	virtual ~WorldManager();

	std::list<World*> m_WorldList;

	World* m_currWorld = nullptr;

public:
	void ChangeWorld(std::string worldName);

	void Update(float deltaTime);
	void Render(ID2D1RenderTarget* pRenderTarget);
	void Clear();
};
