#include "Sprite.hpp"
#include "Transform.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"
#include "ZII2/Math/Matrix.hpp"

namespace ZII2
{

const ComponentID Sprite::ID = ComponentID::Sprite;

Sprite::Sprite(Cog * owner)
  : Graphical(owner), mR(0xFF), mG(0xFF), mB(0xFF), mA(0xFF),
    mBlendMode(ZBlendMode::Blend), mFlipX(false), mFlipY(false),
    mTexture(nullptr)
{}

Sprite::~Sprite() {}

void Sprite::Render(Renderer * renderer)
{
  //mTransform->Update();

  //Pixit2 origin = Pixit2::Zero;
  //auto originTransformed = mTransform->TransformPoint(origin);

  auto position = mTransform->GetPosition();
  auto rotation = mTransform->GetRotation();
  auto scale = mTransform->GetScale();
  int x = int(position.mX);
  int y = int(position.mY);
  int w = mTexture->GetWidth();
  int h = mTexture->GetHeight();
  double angle = double(rotation);
  float scaleX = float(scale.mX);
  float scaleY = float(scale.mY);
  ZRect * srcrect = nullptr;
  ZPoint center = ZPoint{ 0, 0 };
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

  renderer->Render(mTexture, srcrect, &dstrect, angle, &center, flip);
}

} // namespace ZII2
