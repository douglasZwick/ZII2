#include "Sprite.hpp"
#include "Transform.hpp"

namespace ZII2
{

Sprite::Sprite(Cog * owner)
  : Graphical(owner), mR(0xFF), mG(0xFF), mB(0xFF), mA(0xFF),
    mBlendMode(SDL_BLENDMODE_BLEND), mFlipX(false), mFlipY(false),
    mTexture(nullptr)
{}

Sprite::~Sprite() {}

void Sprite::Render(SDL_Renderer * renderer)
{
  int x = mTransform->mPosX;
  int y = mTransform->mPosY;
  int w = mTexture->GetWidth();
  int h = mTexture->GetHeight();
  double angle = mTransform->mAngle;
  float scaleX = mTransform->mScaleX;
  float scaleY = mTransform->mScaleY;
  SDL_Rect * clip = nullptr;
  SDL_Point * center = nullptr;
  SDL_Rect renderQuad = { x, y, w, h };

  if (clip != nullptr)
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  renderQuad.w = int(renderQuad.w * scaleX);
  renderQuad.h = int(renderQuad.h * scaleY);

  SDL_RendererFlip flip = (SDL_RendererFlip)(int(mFlipX) | (int(mFlipY) * 2));

  mTexture->SetColor(mR, mG, mB);
  mTexture->SetAlpha(mA);
  mTexture->SetBlendMode(mBlendMode);

  SDL_RenderCopyEx(renderer, mTexture->mSdlTexture, clip, &renderQuad, angle, center, flip);
}

} // namespace ZII2
