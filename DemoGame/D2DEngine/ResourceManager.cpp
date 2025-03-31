#include "pch.h"
#include "ResourceManager.h"
#include "D2DRenderer.h"

// 게임에 사용되는 데이터들 관리
// 이미지, 사운드, 폰트 등

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

bool ResourceManager::CreateD2DBitmapFromFile(std::wstring strFilePath, ID2D1Bitmap** bitmap, D2DRenderer* d2d)
{
	return false;
}

void ResourceManager::ReleaseD2DBitmap(std::wstring strFilePath)
{

}

//bool ResourceManager::CreateAnimationAsset(std::wstring strFilePath, AnimationAsset** asset)
//{
//	return false;
//}

//void ResourceManager::ReleaseAnimationAsset(std::wstring strFilePath)
//{
//	
//}