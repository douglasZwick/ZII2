#include "Cog.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"

namespace ZII2
{

Cog::Cog()
  : mParent(nullptr)
{
  for (size_t i = 0; i < size_t(ComponentID::_Count); ++i)
    mComponents[i] = nullptr;
}

Cog::~Cog()
{
  // destroy all the components
  // TODO: ask claeys or someone how better to do this
  Remove<Transform>();
  Remove<Sprite>();
}

Cog * Cog::GetParent() const
{
  return mParent;
}

//void Cog::AttachTo(Cog * newParent)
//{
//
//}

void Cog::AttachToNoRecompute(Cog * newParent)
{
  mParent = newParent;
}

void Cog::Detach()
{
  mParent = nullptr;
}

} // namespace ZII2
