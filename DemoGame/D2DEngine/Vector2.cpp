#include "pch.h"
#include "Vector2.h"

const Vector2 Right{ 1,0 };
const Vector2 Left{ -1,0 };
const Vector2 Up{ 0, 1 };
const Vector2 Down{ 0, -1 };

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(double x, double y)
{
	this->x = (float)x;
	this->y = (float)y;
}

Vector2::Vector2(int x, int y)
{
	this->x = float(x);
	this->y = float(y);
}

Vector2::Vector2(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
}

Vector2 Vector2::Normalize()
{
	float length = Length();

	if (length > 0.f)
	{
		return Vector2{ x / length, y / length };
	}

	return Vector2{ 0.f, 0.f };
}

float Vector2::Length()
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Lerp(const Vector2& start, const Vector2& end, const float t)
{
	Vector2 lerpVec = { (1.f - t) * start.x + t * end.x, (1.f - t) * start.y + t * end.y };

	return lerpVec;
}

Vector2& Vector2::operator=(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

Vector2 Vector2::operator*(const float sclas)
{
	Vector2 mulVec = { this->x * sclas, this->y * sclas };

	return mulVec;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 addVec = { this->x + other.x, this->y + other.y };

	return addVec;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 subVec = { this->x - other.x, this->y - other.y };

	return subVec;
}

bool Vector2::operator==(const Vector2& other)
{
	return (this->x != other.x || this->y != other.y);
}

bool Vector2::operator!=(const Vector2& other)
{
	return (this->x == other.x && this->y == other.y);
}
