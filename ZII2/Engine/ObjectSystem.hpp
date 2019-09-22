#ifndef OBJECTSYSTEM_H
#define OBJECTSYSTEM_H

#include "ForwardDeclarations.hpp"
#include "System.hpp"

namespace ZII2
{

class ObjectSystem : public System
{
public:
  ObjectSystem(Engine * engine);
  ~ObjectSystem();

  void Add(Cog * cog);
  void Update(double dt) override;
  
private:
  struct Impl;

  Impl * mImpl;
}; // class ObjectSystem

} // namespace ZII2

#endif // OBJECTSYSTEM_H
