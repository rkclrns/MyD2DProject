#include "../D2DEngine/pch.h"
#include "Player.h"
#include "Bullet.h"
#include "../D2DEngine/SpriteRenderer.h"
#include "../D2DEngine/BoxCollider.h"
#include "../D2DEngine/SceneManager.h"
#include "../D2DEngine/LineRenderer.h"

Player::Player()
	: GameObject()
{
	sprite->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Coromon", L"../Resource/Coromon.png"));
	transform->SetPosition(Vector2(960 - sprite->GetSprite()->GetSize().x / 2, 700.f));
	transform->SetPivot(Vector2(150, 150));
	boxCollider->SetSize(300, 300);

	lineRenderer = AddComponent<LineRenderer>();
	lineRenderer->SetLineColor(D2D1::ColorF(D2D1::ColorF::Red)); // 빨간색
	lineRenderer->SetLineWidth(20.f);
}

Player::~Player()
{
}

void Player::PreUpdate()
{
	__super::PreUpdate();
}

void Player::Update()
{
	__super::Update();

	// 1. 플레이어 위치 가져오기
	Vector2 playerPos = transform->position + transform->pivot;

	// 2. aimAngle에 따라 방향 벡터 계산
	Vector2 direction = Vector2(cosf(aimAngle), sinf(aimAngle));

	// 3. 방향 벡터에 길이 곱해서 선 끝점 구하기
	Vector2 endPoint = playerPos + direction * aimLength;

	// 4. 조준선 위치 설정
	if (lineRenderer)
	{
		lineRenderer->SetStartPoint(playerPos);
		lineRenderer->SetEndPoint(endPoint);
	}

	// 입력에 따라 aimAngle 조정
	if (InputSystem::GetKeyDown(eKeyCode::LEFT))
	{
		aimAngle -= 0.05f; // ← 좌측 회전
	}
	if (InputSystem::GetKeyDown(eKeyCode::RIGHT))
	{
		aimAngle += 0.05f; // → 우측 회전
	}

	// 스페이스바로 불렛 발사
	if (InputSystem::GetKeyDown(eKeyCode::SPACE))
		FireBullet();

}

void Player::PostUpdate()
{
	__super::PostUpdate();
}

void Player::PreRender()
{
	__super::PreRender();
}

void Player::Render()
{
	__super::Render();
}

void Player::PostRender()
{
	__super::PostRender();
}

void Player::FireBullet()
{
	//Bullet* bullet = SceneManager::GetActiveScene()->CreateGameObject<Bullet>(L"Bullet", eObjectTag::BULLET);

	//Vector2 dir = Vector2(cos(shootAngle), sin(shootAngle));
	//dir.Normalize();

	//bullet->transform->SetPosition(this->transform->position + dir * 80.0f); // 총구 앞
	//bullet->SetDirection(dir);
}
