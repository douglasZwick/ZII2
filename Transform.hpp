#ifndef TRANFORM_H
#define TRANFORM_H

#include "Component.hpp"

namespace ZII2
{

class Transform : public Component
{
public:
  
  
  Transform(Cog * owner);
  ~Transform();
}; // class Transform

} // namespace ZII2

#endif // TRANFORM_H
