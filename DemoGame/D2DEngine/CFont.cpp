#include "pch.h"
#include "CFont.h"

CFont::CFont()
{
	mType = eResourceType::FONT;
}

CFont::~CFont()
{
}

bool CFont::Load()
{
	m_pTextFormat = D2DRenderer::GetInstance()->CreateD2DFont(mFontName.c_str(), mSize, mWeight, mStyle, mStretch);
	assert(m_pTextFormat != nullptr);

	return true;
}

std::wstring CFont::GetFontName()
{
	return mFontName;
}

float CFont::GetSize()
{
	return mSize;
}

DWRITE_FONT_WEIGHT CFont::GetWeight()
{
	return mWeight;
}

DWRITE_FONT_STYLE CFont::GetStyle()
{
	return mStyle;
}

DWRITE_FONT_STRETCH CFont::GetStreth()
{
	return mStretch;
}

IDWriteTextFormat* CFont::GetTextFormat()
{
	return m_pTextFormat;
}

void CFont::SetFontName(const std::wstring name)
{
	mFontName = name;
}

void CFont::SetSize(const float size)
{
	mSize = size;
}

void CFont::SetWeight(const DWRITE_FONT_WEIGHT weight)
{
	mWeight = weight;
}

void CFont::SetStyle(const DWRITE_FONT_STYLE style)
{
	mStyle = style;
}

void CFont::SetStreth(const DWRITE_FONT_STRETCH stretch)
{
	mStretch = stretch;
}
