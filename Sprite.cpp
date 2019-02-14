#include "Sprite.hpp"

namespace ZII2
{

Sprite::Sprite(Cog * owner)
  : Graphical(owner)
{}

Sprite::~Sprite() {}

void Sprite::Render(SDL_Renderer * renderer)
{
  int x = 300;
  int y = 300;
  int w = mTexture->GetWidth();
  int h = mTexture->GetHeight();
  float scaleX = 1.0f;
  float scaleY = 1.0f;
  double angle = 0.0;
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
