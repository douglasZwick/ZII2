#ifndef SYSTEM_H
#define SYSTEM_H

#include "ForwardDeclarations.hpp"

namespace ZII2
{

class System
{
public:
  Engine * mEngine;
  
  System(Engine * engine);
  ~System();

  virtual void Update(double dt) = 0;
}; // class System

} // namespace ZII2

#endif // SYSTEM_H
