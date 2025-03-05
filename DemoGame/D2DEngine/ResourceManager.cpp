#include "pch.h"
#include "ResourceManager.h"
#include "D2DRenderer.h"

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

void ResourceManager::ReleaseAnimationAsset(std::wstring strFilePath)
{
	
}