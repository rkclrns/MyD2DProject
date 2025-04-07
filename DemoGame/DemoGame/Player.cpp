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
	m_pLineRenderer->SetLineColor(D2D1::ColorF(D2D1::ColorF::Gray)); // ������
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

	// �Է¿� ���� aimAngle ����
	if (InputSystem::GetKeyPressed(eKeyCode::A))
	{
		m_pSprite->SetFlipX(false);
		// ���� ȸ��
		mAngleDeg -= mRotationSpeed * TimeSystem::GetDeltaTime();
	}
	if (InputSystem::GetKeyPressed(eKeyCode::D))
	{
		m_pSprite->SetFlipX(true);
		// ���� ȸ��
		mAngleDeg += mRotationSpeed * TimeSystem::GetDeltaTime();
	}

	// clamp ó��: -90 ~ +90 ���̷� ����
	if (mAngleDeg < -180.0f) mAngleDeg = -180.0f;
	if (mAngleDeg > 0.0f) mAngleDeg = 0.0f;

	float angleRad = mAngleDeg * (3.14159265f / 180.0f);

	float x = cos(angleRad) * mRadius;
	float y = sin(angleRad) * mRadius;

	// �÷��̾� �߾� ��ġ ��������
	Vector2 startPos = transform->position + transform->pivot;

	// ���� ���Ϳ� ���� ���ؼ� �� ���� ���ϱ�
	Vector2 endPos{ startPos.x + x, startPos.y + y};

	// ���� ��ġ ����
	if (m_pLineRenderer)
	{
		m_pLineRenderer->SetStartPoint(startPos);
		m_pLineRenderer->SetEndPoint(endPos);
	}


	// �����̽��ٷ� �ҷ� �߻�
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
	// ���� ���� (���� ����)
	Vector2 direction = dir;

	// �Ѿ� ����
	Bullet* bullet = SceneManager::GetActiveScene()->CreateGameObject<Bullet>(L"Bullet",eObjectTag::BULLET);
	bullet->transform->SetPosition(transform->position + transform->pivot);
	bullet->SetDirection(direction);
	bullet->SetSpeed(1000.0f); // ������ �ӵ� ����
}
