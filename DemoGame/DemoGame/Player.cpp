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
	lineRenderer->SetLineColor(D2D1::ColorF(D2D1::ColorF::Red)); // ������
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

	// 1. �÷��̾� ��ġ ��������
	Vector2 playerPos = transform->position + transform->pivot;

	// 2. aimAngle�� ���� ���� ���� ���
	Vector2 direction = Vector2(cosf(aimAngle), sinf(aimAngle));

	// 3. ���� ���Ϳ� ���� ���ؼ� �� ���� ���ϱ�
	Vector2 endPoint = playerPos + direction * aimLength;

	// 4. ���ؼ� ��ġ ����
	if (lineRenderer)
	{
		lineRenderer->SetStartPoint(playerPos);
		lineRenderer->SetEndPoint(endPoint);
	}

	// �Է¿� ���� aimAngle ����
	if (InputSystem::GetKeyDown(eKeyCode::LEFT))
	{
		aimAngle -= 0.05f; // �� ���� ȸ��
	}
	if (InputSystem::GetKeyDown(eKeyCode::RIGHT))
	{
		aimAngle += 0.05f; // �� ���� ȸ��
	}

	// �����̽��ٷ� �ҷ� �߻�
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

	//bullet->transform->SetPosition(this->transform->position + dir * 80.0f); // �ѱ� ��
	//bullet->SetDirection(dir);
}
