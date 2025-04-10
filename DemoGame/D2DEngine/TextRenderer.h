#pragma once
#include "Component.h"
#include "CFont.h"

class TextRenderer
	: public Component
{
public:
	TextRenderer();
	~TextRenderer();

	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void Render() override;
	void Destroy() override;

	CFont*& GetCFont() { return m_pFont; }

	void SetColor(D2D1_COLOR_F color);
	void SetTextBox(D2D1_RECT_F& box);
	void SetAlpha(float alpha);
	void SetText(const std::wstring& text);

	const std::wstring GetText();

private:
	CFont* m_pFont = nullptr;
	std::wstring mText = L"";
	D2D1_RECT_F mTextBox{};
	D2D1_COLOR_F mColor = D2D1::ColorF(D2D1::ColorF::White);
	float mAlpha = 1.f;
};

