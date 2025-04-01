#pragma once
#include "Resource.h"

class CFont
	: public Resource
{
public:
	CFont();
	~CFont();

	bool Load() override;

	std::wstring GetFontName();
	float GetSize();
	DWRITE_FONT_WEIGHT GetWeight();
	DWRITE_FONT_STYLE GetStyle();
	DWRITE_FONT_STRETCH GetStreth();

	void SetFontName(const std::wstring name);
	void SetSize(const float size);
	void SetWeight(const DWRITE_FONT_WEIGHT weight);
	void SetStyle(const DWRITE_FONT_STYLE style);
	void SetStreth(const DWRITE_FONT_STRETCH stretch);

private:
	IDWriteTextFormat* m_pTextFormat;

	std::wstring mFontName;
	float mSize = 10.f;
	DWRITE_FONT_WEIGHT mWeight = DWRITE_FONT_WEIGHT_NORMAL;
	DWRITE_FONT_STYLE mStyle = DWRITE_FONT_STYLE_NORMAL;
	DWRITE_FONT_STRETCH mStretch = DWRITE_FONT_STRETCH_NORMAL;
};

