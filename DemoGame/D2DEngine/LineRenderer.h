#pragma once
#include "Component.h"
#include "Vector2.h"

class LineRenderer
	: public Component
{
public:
	LineRenderer();
	~LineRenderer();

	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	void SetStartPoint(Vector2 start) { mStartPoint = start; }
	void SetEndPoint(Vector2 end) { mEndPoint = end; }
	void SetLineColor(D2D1_COLOR_F color) { mColor = color; }
	void SetLineWidth(float width) { mWidth = width; }

	Vector2 GetStartPoint() { return mStartPoint; }
	Vector2 GetEndPoint() { return mEndPoint; }
private:
	Vector2 mStartPoint{};
	Vector2 mEndPoint{};
	D2D1_COLOR_F mColor{};
	float mWidth = 1.f;
};

