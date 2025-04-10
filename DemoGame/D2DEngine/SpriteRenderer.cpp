#include "pch.h"
#include "SpriteRenderer.h"
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

void SpriteRenderer::Render()
{
	if (mSprite)
	{
		auto transform = GetOwner()->transform;
		D2D1_MATRIX_3X2_F world = transform->GetWorldMatrix();

		if (mFlipX || mFlipY)
		{
			// 중심점 설정 (피벗 기준)
			D2D1_POINT_2F center =
			{
				transform->pivot.x,
				transform->pivot.y
			};

			// 스케일 값 계산
			float scaleX = mFlipX ? -1.0f : 1.0f;
			float scaleY = mFlipY ? -1.0f : 1.0f;

			// 반전 행렬 만들고 곱해주기
			D2D1_MATRIX_3X2_F flip =
				D2D1::Matrix3x2F::Scale(scaleX, scaleY, center);

			world = flip * world;
		}

		D2DRenderer::GetInstance()->DrawBitmap(mSprite->GetBitamp(), world);
	}
}

void SpriteRenderer::Destroy()
{
}

