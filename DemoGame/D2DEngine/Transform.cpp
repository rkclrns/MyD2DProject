#include "pch.h"
#include "Transform.h"

Transform::Transform()
{
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

void Transform::UpdateWorldMatrix()
{
    // ���� ��� ���
    mScale = D2D1::Matrix3x2F::Scale(scale.x, scale.y);
    mRotation = D2D1::Matrix3x2F::Rotation(rotation);
    mPosition = D2D1::Matrix3x2F::Translation(position.x, position.y);

    // ���� ��ȯ ��� ��� 
    // (Scale �� Rotation �� Translation ����)
    worldMatrix = mScale * mRotation * mPosition;

    if (parent) {
        worldMatrix = parent->worldMatrix * worldMatrix;
    }

    // �ڽĵ鵵 ��� ���
    for (Transform* child : childsList) {
        child->UpdateWorldMatrix();
    }
}
