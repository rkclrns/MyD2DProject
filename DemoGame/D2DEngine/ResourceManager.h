#pragma once
#include "Resource.h"
#include <map>
#include <assert.h>

class ResourceManager
{
public:

	static ResourceManager* GetInstance();
	static void DestroyInstance();

	template <typename T>
	T* Find(const std::wstring& key)
	{
		std::map<std::wstring, Resource*>::iterator itr = mResources.find(key);

		if (itr == mResources.end())
			return nullptr;

		return dynamic_cast<T*>(itr->second);
	}

	template <typename T>
	T* Load(const std::wstring& key, const std::wstring& path)
	{
		bool bIsBase = std::is_base_of<Resource, T>::value;	// 리소스 상속 받은 것만 가능함
		assert(bIsBase == true);

		T* resource = ResourceManager::Find<T>(key);

		if (resource)
			return resource;

		resource = new T();
		resource->SetName(key);
		resource->SetPath(path);

		if (!resource->Load())
			assert(false && "Resource Load Failed!");

		mResources.insert(std::make_pair(key, resource));

		return resource;
	}

private:

	ResourceManager();
	~ResourceManager();

	// 복사 & 대입 연산자 삭제
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	static ResourceManager* pInstance;

	std::map<std::wstring, Resource*> mResources;
};