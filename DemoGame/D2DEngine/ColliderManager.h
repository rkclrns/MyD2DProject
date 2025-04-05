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

	// 둘이 충돌처리를 해야되는 대상인지
	static bool IsCollision(eObjectTag a, eObjectTag b);
};

