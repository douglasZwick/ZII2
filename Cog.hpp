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
  Transform * mTransform;
  Sprite *    mSprite;

  Cog();
  ~Cog();
}; // class Cog

} // namespace ZII2

#endif // COG_H
