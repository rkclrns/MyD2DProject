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

}

Player::~Player()
{
}

void Player::Initialize()
{
	__super::Initialize();

	m_pLineRenderer = AddComponent<LineRenderer>();
	m_pLineRenderer->SetLineColor(D2D1::ColorF(D2D1::ColorF::Gray)); // 빨간색
	m_pLineRenderer->SetLineWidth(3.f);

	m_pSprite = AddComponent<SpriteRenderer>();
	m_pSprite->SetSprite(ResourceManager::GetInstance()->
		Load<Sprite>(L"Coromon", L"../Resource/Coromon.png"));
	transform->SetPosition(Vector2(960 - m_pSprite->GetSprite()->GetSize().x / 2, 700.f));
	transform->SetPivot(Vector2(150, 150));
	boxCollider->SetSize(300, 300);
}

void Player::PreUpdate()
{
	__super::PreUpdate();
}

void Player::Update()
{
	__super::Update();

	// 입력에 따라 aimAngle 조정
	if (InputSystem::GetKeyPressed(eKeyCode::A))
	{
		m_pSprite->SetFlipX(false);
		// 좌측 회전
		mAngleDeg -= mRotationSpeed * TimeSystem::GetDeltaTime();
	}
	if (InputSystem::GetKeyPressed(eKeyCode::D))
	{
		m_pSprite->SetFlipX(true);
		// 우측 회전
		mAngleDeg += mRotationSpeed * TimeSystem::GetDeltaTime();
	}

	// clamp 처리: -90 ~ +90 사이로 고정
	if (mAngleDeg < -180.0f) mAngleDeg = -180.0f;
	if (mAngleDeg > 0.0f) mAngleDeg = 0.0f;

	float angleRad = mAngleDeg * (3.14159265f / 180.0f);

	float x = cos(angleRad) * mRadius;
	float y = sin(angleRad) * mRadius;

	// 플레이어 중앙 위치 가져오기
	Vector2 startPos = transform->position + transform->pivot;

	// 방향 벡터에 길이 곱해서 선 끝점 구하기
	Vector2 endPos{ startPos.x + x, startPos.y + y};

	// 라인 위치 설정
	if (m_pLineRenderer)
	{
		m_pLineRenderer->SetStartPoint(startPos);
		m_pLineRenderer->SetEndPoint(endPos);
	}


	// 스페이스바로 불렛 발사
	if (InputSystem::GetKeyDown(eKeyCode::SPACE))
		FireBullet(endPos - startPos);
}

void Player::Render()
{
	__super::Render();
}

void Player::Destroy()
{
}

void Player::FireBullet(Vector2 dir)
{
	// 방향 벡터 (단위 벡터)
	Vector2 direction = dir;

	// 총알 생성
	Bullet* bullet = SceneManager::GetActiveScene()->CreateGameObject<Bullet>(L"Bullet",eObjectTag::BULLET);
	bullet->transform->SetPosition(transform->position + transform->pivot);
	bullet->SetDirection(direction);
	bullet->SetSpeed(1000.0f); // 적당한 속도 설정
}
