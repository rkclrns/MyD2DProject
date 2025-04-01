#include "pch.h"
#include "ResourceManager.h"

// 게임에 사용되는 데이터들 관리
// 이미지, 사운드, 폰트 등

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

ResourceManager* ResourceManager::pInstance = nullptr;

ResourceManager* ResourceManager::GetInstance()
{
	if (!pInstance)
		pInstance = new ResourceManager();

	return pInstance;
}

void ResourceManager::DestroyInstance() 
{
	delete pInstance;  // 해제
	pInstance = nullptr;
}