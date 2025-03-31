#include "pch.h"
#include "Transform.h"

Transform::Transform()
    : Component(eComponentType::Transform)
{
    UpdateWorldMatrix();
}

Transform::~Transform()
{
}

void Transform::PreUpdate()
{
}

void Transform::Update()
{
    UpdateWorldMatrix();
}

void Transform::PostUpdate()
{
}

void Transform::PreRender()
{
}

void Transform::Render()
{
}

void Transform::PostRender()
{
}

void Transform::SetParent(Transform* parent)
{
    this->parent = parent;
    parent->childsList.push_back(this);
}

void Transform::SetPosition(const Vector2& position) {
    this->position = position;
    UpdateWorldMatrix();
}

void Transform::SetRotation(float rotation) {
    this->rotation = rotation;
    UpdateWorldMatrix();
}

void Transform::SetScale(const Vector2& scale) {
    this->scale = scale;
    UpdateWorldMatrix();
}

void Transform::SetPivot(const Vector2& pivot)
{
    this->pivot = pivot;
    UpdateWorldMatrix();
}

void Transform::UpdateWorldMatrix()
{
    // 중심 기준 행렬 추가
    mPivot = D2D1::Matrix3x2F::Translation(pivot.x, pivot.y);
    mInversPivot = D2D1::Matrix3x2F::Translation(-pivot.x, -pivot.y);

    // 로컬 행렬 계산
    mScale = D2D1::Matrix3x2F::Scale(scale.x, scale.y);
    mRotation = D2D1::Matrix3x2F::Rotation(rotation);
    mPosition = D2D1::Matrix3x2F::Translation(position.x, position.y);

    // 월드 변환 행렬 계산 
    // (Scale → Rotation → Translation 순서)
    worldMatrix = mInversPivot * mScale * mRotation * mPivot * mPosition;

    if (parent) {
        worldMatrix = parent->worldMatrix * worldMatrix;
    }

    // 자식들도 행렬 계산
    for (Transform* child : childsList) {
        child->UpdateWorldMatrix();
    }
}
