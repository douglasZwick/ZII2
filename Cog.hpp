#ifndef COG_H
#define COG_H

#include "Component.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"

namespace ZII2
{

class Cog
{
public:


  Cog();
  ~Cog();

  Transform * GetTransform();
  Sprite *    GetSprite();

private:
  Transform * mTransform;
  Sprite *    mSprite;
}; // class Cog

} // namespace ZII2

#endif // COG_H
