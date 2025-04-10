#pragma once
#include "..\D2DEngine\Scene.h"

class Player;
class Enemy;
class TextRenderer;
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
	GameObject* text = nullptr;
	TextRenderer* textRenderer = nullptr;

	float spawnTimer = 0.0f;
	float spawnInterval = 2.0f;
	int score = 0;
};

