#include "pch.h"
#include "LineRenderer.h"
#include "GameObject.h"

LineRenderer::LineRenderer()
	: Component(eComponentType::LineRenderer)
{
}

LineRenderer::~LineRenderer()
{
}

void LineRenderer::Initialize()
{
}

void LineRenderer::PreUpdate()
{
}

void LineRenderer::Update()
{
}

void LineRenderer::PostUpdate()
{
}

void LineRenderer::PreRender()
{
}

void LineRenderer::Render()
{
	D2D1_POINT_2F start = { mStartPoint.x, mStartPoint.y };
	D2D1_POINT_2F end = { mEndPoint.x, mEndPoint.y };

	D2DRenderer::GetInstance()->DrawLine(start, end, mColor, 1.0f, mWidth);
}

void LineRenderer::PostRender()
{
}
