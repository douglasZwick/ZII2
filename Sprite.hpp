#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "Graphical.hpp"
#include "ZTexture.hpp"

namespace ZII2
{

class Sprite : public Graphical
{
public:
  Uint8 mR;
  Uint8 mG;
  Uint8 mB;
  Uint8 mA;
  SDL_BlendMode mBlendMode;
  bool mFlipX;
  bool mFlipY;
  ZTexture * mTexture;

  Sprite(Cog * owner);
  ~Sprite();

  // renders this bad boy
  void Render(SDL_Renderer * renderer) override;
}; // class Sprite

} // namespace ZII2

#endif // SPRITE_H
