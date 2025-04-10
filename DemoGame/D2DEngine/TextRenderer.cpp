#include "pch.h"
#include "TextRenderer.h"
#include "GameObject.h"
#include "WinApp.h"

TextRenderer::TextRenderer()
	: Component(eComponentType::TextRenderer)
{
	
}

TextRenderer::~TextRenderer()
{
}

void TextRenderer::Initialize()
{
	mTextBox = { 0, 0, (float)WinApp::GetWidth(), 0 };
}

void TextRenderer::PreUpdate()
{
}

void TextRenderer::Update()
{

}

void TextRenderer::Render()
{
	if (m_pFont && !mText.empty())
	{
		D2DRenderer::GetInstance()->DrawTextW(mText.c_str(), m_pFont->GetTextFormat(), mTextBox, mColor, mAlpha);
	}
}

void TextRenderer::Destroy()
{
	if(m_pFont != nullptr)
		delete m_pFont;
}

void TextRenderer::SetColor(D2D1_COLOR_F color)
{
	mColor = color;
}

void TextRenderer::SetTextBox(D2D1_RECT_F& box)
{
	mTextBox = box;
}

void TextRenderer::SetAlpha(float alpha)
{
	alpha = mAlpha;
}

void TextRenderer::SetText(const std::wstring& text)
{
	mText = text;
}

const std::wstring TextRenderer::GetText()
{
	return mText;
}
