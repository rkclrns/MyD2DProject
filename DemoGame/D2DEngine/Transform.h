#pragma once
#include "Component.h"
#include "Vector2.h"

class Vector2;

class Transform
	: public Component
{
public:
	Transform();
	~Transform();

	Vector2 position = Vector2(0, 0);
	float rotation = 0.f;
	Vector2 scale = Vector2(1, 1);

	void PreUpdate();
	void Update();
	void PostUpdate();
	void PreRender();
	void Render();
	void PostRender();

	void SetParent(Transform* parent);
	void SetPosition(const Vector2& position);
	void SetRotation(float rotation);
	void SetScale(const Vector2& scale);

	Transform* GetParent() { return parent; }
	D2D1_MATRIX_3X2_F& GetWorldMatrix() { return worldMatrix; }

private:
	Transform* parent = nullptr;
	std::list<Transform*> childsList;

	D2D1_MATRIX_3X2_F worldMatrix;

	D2D1_MATRIX_3X2_F mPosition;
	D2D1_MATRIX_3X2_F mRotation;
	D2D1_MATRIX_3X2_F mScale;

	void UpdateWorldMatrix();
};

