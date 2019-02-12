#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "Component.hpp"

namespace ZII2
{

class Sprite : public Component
{
public:
  bool mFlipX;
  bool mFlipY;
  
  Sprite();
  ~Sprite();

private:
  SDL_Texture * mTexture;
}; // class Sprite

} // namespace ZII2

#endif // SPRITE_H
