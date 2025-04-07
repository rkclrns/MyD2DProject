#pragma once
#include "..\D2DEngine\GameObject.h"


class SpriteRenderer;
class Enemy :
	public GameObject
{
public:
	Enemy();
	virtual ~Enemy();

	void Initialize();
	void PreUpdate();
	void Update();
	void Render();
	void Destroy();

public:

private:
	SpriteRenderer* m_pSprite = nullptr;
};

