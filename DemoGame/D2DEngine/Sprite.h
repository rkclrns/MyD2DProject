#pragma once
#include "Resource.h"
#include "Vector2.h"

class ID2D1Bitmap;

class Sprite
	: public Resource
{
public:
	Sprite();
	~Sprite();

	bool Load() override;

	ID2D1Bitmap* GetBitamp();
	Vector2& GetSize();
	Vector2& GetCenter();

private:
	ID2D1Bitmap* m_pBitmap = nullptr;
	Vector2 mSize{};
	Vector2 mCenter{};
};

