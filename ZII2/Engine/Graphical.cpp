#include "Graphical.hpp"
#include "Cog.hpp"
#include "Transform.hpp"

namespace ZII2
{

Graphical::Graphical(Cog * owner)
  : Component(owner), mTransform(owner->Get<Transform>())
{}

Graphical::~Graphical() {}

} // namespace ZII2
