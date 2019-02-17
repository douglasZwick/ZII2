#include "Sprite.hpp"
#include "Transform.hpp"
#include "ZTexture.hpp"
#include "Renderer.hpp"

namespace ZII2
{

Sprite::Sprite(Cog * owner)
  : Graphical(owner), mR(0xFF), mG(0xFF), mB(0xFF), mA(0xFF),
    mBlendMode(ZBlendMode::Blend), mFlipX(false), mFlipY(false),
    mTexture(nullptr)
{}

Sprite::~Sprite() {}

void Sprite::Render(Renderer * renderer)
{
  int x = mTransform->mPosX;
  int y = mTransform->mPosY;
  int w = mTexture->GetWidth();
  int h = mTexture->GetHeight();
  double angle = mTransform->mAngle;
  float scaleX = mTransform->mScaleX;
  float scaleY = mTransform->mScaleY;
  ZRect * srcrect = nullptr;
  ZPoint * center = nullptr;
  ZRect dstrect = { x, y, w, h };

  if (srcrect != nullptr)
  {
    dstrect.w = srcrect->w;
    dstrect.h = srcrect->h;
  }

  dstrect.w = int(dstrect.w * scaleX);
  dstrect.h = int(dstrect.h * scaleY);

  ZFlip flip = static_cast<ZFlip>(int(mFlipX) | (int(mFlipY) * 2));

  mTexture->SetColor(mR, mG, mB);
  mTexture->SetAlpha(mA);
  mTexture->SetBlendMode(mBlendMode);

  renderer->Render(mTexture, srcrect, &dstrect, angle, center, flip);
}

} // namespace ZII2
