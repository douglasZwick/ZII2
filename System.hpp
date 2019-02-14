#ifndef SYSTEM_H
#define SYSTEM_H

namespace ZII2
{

class Engine;

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
