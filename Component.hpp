#ifndef COMPONENT_H
#define COMPONENT_H

namespace ZII2
{

class Cog;

class Component
{
public:
  Cog * mOwner;
  
  Component(Cog * owner);
  ~Component();
}; // class Component

} // namespace ZII2

#endif // COMPONENT_H
