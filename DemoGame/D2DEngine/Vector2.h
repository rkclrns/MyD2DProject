#pragma once

class Vector2
{
public:
	float x;
	float y;

	Vector2(float x = 0, float y = 0);
	Vector2(double x, double y);
	Vector2(int x, int y);
	~Vector2() = default;

	Vector2(const Vector2& other);

	Vector2 Normalize();
	float Length();
	Vector2 Lerp(const Vector2& start, const Vector2& end, const float t);

	Vector2& operator = (const Vector2& other);
	Vector2& operator += (const Vector2& other);
	Vector2& operator -= (const Vector2& other);
	Vector2 operator * (const float sclas);
	Vector2 operator + (const Vector2& other);
	Vector2 operator - (const Vector2& other);
	bool operator == (const Vector2& other);
	bool operator != (const Vector2& other);
};

