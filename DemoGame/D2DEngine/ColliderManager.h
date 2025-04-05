#pragma once

enum class eObjectTag;

class ColliderManager
{
public:
	static void Initialize();
	static void PreUpdate();
	static void Update();
	static void LateUpdate();
	static void Render();

	// ���� �浹ó���� �ؾߵǴ� �������
	static bool IsCollision(eObjectTag a, eObjectTag b);
};

