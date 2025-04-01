#pragma once
#include "Component.h"
#include "Sprite.h"

class SpriteRenderer
	: public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize();
	void PreUpdate();
	void Update();
	void PostUpdate();
	void PreRender();
	void Render();
	void PostRender();

	void SetSprite(Sprite* sprite) { mSprite = sprite; }
	Sprite* GetSprite() { return mSprite; }

private:
	Sprite* mSprite = nullptr;
};

