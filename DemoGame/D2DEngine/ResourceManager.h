#pragma once

class D2DRenderer;
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* pInstance;

	std::map<std::wstring, ID2D1Bitmap*> m_BitmapMap;
	bool CreateD2DBitmapFromFile(std::wstring strFilePath, ID2D1Bitmap** bitmap, D2DRenderer* d2d);
	void ReleaseD2DBitmap(std::wstring strFilePath);

	//bool CreateAnimationAsset(std::wstring strFilePath, AnimationAsset** asset);
	void ReleaseAnimationAsset(std::wstring strFilePath);
};