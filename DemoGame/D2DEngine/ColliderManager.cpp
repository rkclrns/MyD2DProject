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
    // 1. 현재 액티브 씬에서 게임오브젝트 리스트 가져오기
    const auto& gameObjects = SceneManager::GetActiveScene()->GetGameObjects();

    // 2. 콜라이더만 모으기
    std::vector<BoxCollider*> colliders;

    for (auto obj : gameObjects)
    {
        // 죽었을때 검사하기
        if (obj == nullptr || obj->IsDead())
          continue;

        BoxCollider* col = obj->boxCollider;
        if (col && col->GetComponentState() == eComponentState::ACTIVE)
            colliders.push_back(col);
    }

    // 3. 전부 false로 초기화
    for (auto col : colliders)
        col->SetColliding(false);

    // 4. 충돌 검사
    for (size_t i = 0; i < colliders.size(); ++i)
    {
        for (size_t j = 0; j < colliders.size(); ++j)
        {
            if (i == j) continue;

            BoxCollider* a = colliders[i];
            BoxCollider* b = colliders[j];

            // 태그 검사
            if (!IsCollision(a->GetOwner()->GetTag(), b->GetOwner()->GetTag()))
                continue;

            // 박스콜라이더만 검사 (임시지만..)
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

    // 1로 채워져있나?
    if (mColliderCheck[row] & (1 << col))
    {
        // 빼주기
        mColliderCheck[row] &= ~(1 << col);
    }
    else
    {
        // 넣어주기
        mColliderCheck[row] |= (1 << col);
    }
}
