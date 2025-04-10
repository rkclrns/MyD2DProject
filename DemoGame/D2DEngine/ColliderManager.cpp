#include "pch.h"
#include "SceneManager.h"
#include "BoxCollider.h"
#include "Component.h"
#include "GameObject.h"

void ColliderManager::Initialize()
{
    mColliderCheck.resize(5, 0);
    CollisionCheck(eObjectTag::BULLET, eObjectTag::ENEMY);
}

std::vector<int> ColliderManager::mColliderCheck;

void ColliderManager::PreUpdate()
{
	
}

void ColliderManager::Update()
{
    // 1. ���� ��Ƽ�� ������ ���ӿ�����Ʈ ����Ʈ ��������
    const auto& gameObjects = SceneManager::GetActiveScene()->GetGameObjects();

    // 2. �ݶ��̴��� ������
    std::vector<BoxCollider*> colliders;

    for (auto obj : gameObjects)
    {
        // �׾����� �˻��ϱ�
        if (obj == nullptr || obj->IsDead())
          continue;

        BoxCollider* col = obj->boxCollider;
        if (col && col->GetComponentState() == eComponentState::ACTIVE)
            colliders.push_back(col);
    }

    // 3. ���� false�� �ʱ�ȭ
    for (auto col : colliders)
        col->SetColliding(false);

    // 4. �浹 �˻�
    for (size_t i = 0; i < colliders.size(); ++i)
    {
        for (size_t j = 0; j < colliders.size(); ++j)
        {
            if (i == j) continue;

            BoxCollider* a = colliders[i];
            BoxCollider* b = colliders[j];

            // �±� �˻�
            if (!IsCollision(a->GetOwner()->GetTag(), b->GetOwner()->GetTag()))
                continue;

            // �ڽ��ݶ��̴��� �˻� (�ӽ�����..)
            /*if (a->GetColliderType() != eColliderType::BOX ||
                b->GetColliderType() != eColliderType::BOX)
                continue;*/

            if (a->isCollide(b))
            {
                a->SetColliding(true);
                b->SetColliding(true);
            }
        }
    }
}


void ColliderManager::LateUpdate()
{

}

void ColliderManager::Render()
{

}

bool ColliderManager::IsCollision(eObjectTag a, eObjectTag b)
{
    int row = static_cast<int>(a);
    int col = static_cast<int>(b);

    if (a > b)
    {
        row = static_cast<int>(b);
        col = static_cast<int>(a);
    }

    if (mColliderCheck[row] & (1 << col))
    {
        return true;
    }
    else
        return false;
}

void ColliderManager::CollisionCheck(eObjectTag a, eObjectTag b)
{
    int row = static_cast<int>(a);
    int col = static_cast<int>(b);

    if (a > b)
    {
        row = static_cast<int>(b);
        col = static_cast<int>(a);
    }

    // 1�� ä�����ֳ�?
    if (mColliderCheck[row] & (1 << col))
    {
        // ���ֱ�
        mColliderCheck[row] &= ~(1 << col);
    }
    else
    {
        // �־��ֱ�
        mColliderCheck[row] |= (1 << col);
    }
}
