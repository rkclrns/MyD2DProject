#pragma once
#include "Resource.h"

class D2DRenderer;

enum class eResourceType
{
	TEXTURE,
	FONT,
	SIZE,
};

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* pInstance;

	bool CreateD2DBitmapFromFile(std::wstring strFilePath, ID2D1Bitmap** bitmap, D2DRenderer* d2d);
	void ReleaseD2DBitmap(std::wstring strFilePath);

	//bool CreateAnimationAsset(std::wstring strFilePath, AnimationAsset** asset);
	//void ReleaseAnimationAsset(std::wstring strFilePath);

	template <typename T>
	static T* Find(const std::wstring& key);

private:
	std::wstring mPath;
	eResourceType mType;
	std::map<std::wstring, Resource*> mResources;
};

template <typename T>
static T* ResourceManager::Find(const std::wstring& key)
{
	std::map<std::wstring, Resource*>::iterator itr = mResources.find(key);

	if (itr == mResources.end())
		return nullptr;

	return dynamic_cast<T*>(itr->second);
}