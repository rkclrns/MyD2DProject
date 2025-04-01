#include "pch.h"
#include "ResourceManager.h"

// ���ӿ� ���Ǵ� �����͵� ����
// �̹���, ����, ��Ʈ ��

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
	delete pInstance;  // ����
	pInstance = nullptr;
}