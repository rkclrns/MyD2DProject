#pragma once
#include <string>

enum class eResourceType
{
	SPRITE,
	FONT,
	SIZE,
};

class Resource
{
public:
	virtual bool Load() = 0;

	std::wstring GetName();
	eResourceType GetType();
	std::wstring GetPath();

	void SetName(const std::wstring name);
	void SetPath(const std::wstring path);
	void SetType(eResourceType type);

protected:
	eResourceType mType;
	std::wstring mPath;
	std::wstring mName;
};

