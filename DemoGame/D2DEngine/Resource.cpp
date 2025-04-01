#include "pch.h"
#include "Resource.h"

std::wstring Resource::GetName()
{
	return mName;
}

eResourceType Resource::GetType()
{
	return mType;
}

std::wstring Resource::GetPath()
{
	return mPath;
}

void Resource::SetName(const std::wstring name)
{
	mName = name;
}

void Resource::SetPath(const std::wstring path)
{
	mPath = path;
}

void Resource::SetType(eResourceType type)
{
	mType = type;
}
