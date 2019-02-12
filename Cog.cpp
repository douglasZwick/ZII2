#include "Cog.hpp"

namespace ZII2
{

Cog::Cog() {}

Cog::~Cog() {}

Transform * Cog::GetTransform()
{
  return mTransform;
}

Sprite * Cog::GetSprite()
{
  return mSprite;
}

} // namespace ZII2
