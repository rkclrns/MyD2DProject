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
			// �߽��� ���� (�ǹ� ����)
			D2D1_POINT_2F center =
			{
				transform->pivot.x,
				transform->pivot.y
			};

			// ������ �� ���
			float scaleX = mFlipX ? -1.0f : 1.0f;
			float scaleY = mFlipY ? -1.0f : 1.0f;

			// ���� ��� ����� �����ֱ�
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

