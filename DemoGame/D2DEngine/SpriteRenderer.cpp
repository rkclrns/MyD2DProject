#include "pch.h"
#include "SpriteRenderer.h"
#include "Sprite.h"
#include "GameObject.h"

SpriteRenderer::SpriteRenderer()
	: Component(eComponentType::SpriteRenderer)
{

}

SpriteRenderer::~SpriteRenderer()
{

}

void SpriteRenderer::Initialize()
{
}

void SpriteRenderer::PreUpdate()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::PostUpdate()
{
}

void SpriteRenderer::PreRender()
{
}

void SpriteRenderer::Render()
{
	if (mSprite)
	{
		D2DRenderer::GetInstance()->DrawBitmap(mSprite->GetBitamp(), GetOwner()->transform->GetWorldMatrix());
	}
}

void SpriteRenderer::PostRender()
{
}
