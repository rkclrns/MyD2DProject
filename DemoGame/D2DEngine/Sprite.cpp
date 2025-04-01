#include "pch.h"
#include "Sprite.h"

Sprite::Sprite()
{
    mType = eResourceType::SPRITE;
}

Sprite::~Sprite()
{
}

bool Sprite::Load()
{
   D2DRenderer::GetInstance()->CreateD2DBitmapFromFile(mPath.c_str(), &m_pBitmap);
   assert(m_pBitmap != nullptr);

   mSize = (m_pBitmap->GetSize().width, m_pBitmap->GetSize().height);
   mCenter = Vector2(m_pBitmap->GetSize().width / 2, m_pBitmap->GetSize().height / 2);

    return true;
}

ID2D1Bitmap* Sprite::GetBitamp()
{
    return m_pBitmap;
}

Vector2& Sprite::GetSize()
{
    return mSize;
}

Vector2& Sprite::GetCenter()
{
    return mCenter;
}
