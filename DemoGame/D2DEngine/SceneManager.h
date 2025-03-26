#pragma once
#include "Scene.h"

// ������ ���踦 ��Ÿ���� Ŭ����
class SceneManager
{
public:

	SceneManager();
	virtual ~SceneManager();

	static std::list<Scene*> m_SceneList;
	static Scene* m_activeScene;

public:
	static void ChangeWorld(std::wstring sceneName);

	static void Initialize();
	static void PreUpdate();
	static void Update();
	static void PostUpdate();
	static void PreRender();
	static void Render();
	static void PostRender();
	static void Clear();
};
