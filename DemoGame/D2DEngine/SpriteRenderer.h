#pragma once
#include "Component.h"
#include "Sprite.h"

class SpriteRenderer
	: public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	void SetFlipX(bool flip) { mFlipX = flip; }
	bool IsFlipX() const { return mFlipX; }

	void SetFlipY(bool flip) { mFlipY = flip; }
	bool IsFlipY() const { return mFlipY; }

	void SetSprite(Sprite* sprite) { mSprite = sprite; }
	Sprite* GetSprite() { return mSprite; }

private:
	Sprite* mSprite = nullptr;
	bool mFlipX = false;
	bool mFlipY = false;
};

