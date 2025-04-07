#pragma once
#include "..\D2DEngine\Scene.h"

class Player;
class Enemy;
class PlayScene :
    public Scene
{
public:
	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;

private:
	GameObject* bg = nullptr;
	GameObject* bg2 = nullptr;
	Player* coromon = nullptr;
	Enemy* kuramon = nullptr;
};

