#ifndef TRANFORM_H
#define TRANFORM_H

#include "ForwardDeclarations.hpp"
#include "Component.hpp"

namespace ZII2
{

class Transform : public Component
{
public:
  int mPosX;
  int mPosY;
  double mAngle;
  float mScaleX;
  float mScaleY;
  
  Transform(Cog * owner);
  ~Transform();
}; // class Transform

} // namespace ZII2

#endif // TRANFORM_H
