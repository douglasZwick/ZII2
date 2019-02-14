#ifndef COMPONENT_H
#define COMPONENT_H

#include "Cog.hpp"

namespace ZII2
{

class Component
{
public:
  Cog * mOwner;
  
  Component(Cog * owner);
  ~Component();
}; // class Component

} // namespace ZII2

#endif // COMPONENT_H
