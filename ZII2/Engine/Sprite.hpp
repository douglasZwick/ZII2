#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>

#include "ForwardDeclarations.hpp"
#include "Types.hpp"
#include "Graphical.hpp"

namespace ZII2
{

class Sprite : public Graphical
{
public:
  static const ComponentID ID;

  uint8_t mR;
  uint8_t mG;
  uint8_t mB;
  uint8_t mA;
  ZBlendMode mBlendMode;
  bool mFlipX;
  bool mFlipY;
  Texture * mTexture;

  Sprite(Cog * owner);
  ~Sprite();

  // renders this bad boy
  void Render(Renderer * renderer) override;
}; // class Sprite

} // namespace ZII2

#endif // SPRITE_H
