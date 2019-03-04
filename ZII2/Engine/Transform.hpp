#ifndef TRANFORM_H
#define TRANFORM_H

#include "ForwardDeclarations.hpp"
#include "Component.hpp"
#include "ZII2/Math/Pixit.hpp"
#include "Types.hpp"

namespace ZII2
{
// hi jorsh
class Transform : public Component
{
public:
  static const ComponentID ID;

  int mPosX;
  int mPosY;
  double mAngle;
  float mScaleX;
  float mScaleY;
  
  Transform(Cog * owner);
  ~Transform();

  Pixit2 const & Position() const;
  Pixit2 & Position();
  Pixit const & Rotation() const;
  Pixit & Rotation();
  Pixit2 const & Scale() const;
  Pixit2 & Scale();

private:
  Pixit2 mPosition;
  Pixit mRotation;
  Pixit2 mScale;
}; // class Transform

} // namespace ZII2

#endif // TRANFORM_H
