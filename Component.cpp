#include "Component.hpp"

namespace ZII2
{

Component::Component(Cog * owner)
  : mOwner(owner)
{}

Component::~Component() {}

} // namespace ZII2
