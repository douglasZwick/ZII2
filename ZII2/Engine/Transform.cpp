#include "Transform.hpp"

namespace ZII2
{

const ComponentID Transform::ID = ComponentID::Transform;

Transform::Transform(Cog * owner)
  : Component(owner), mPosX(0), mPosY(0),
    mAngle(0), mScaleX(1.0f), mScaleY(1.0f),
    mPosition(Pixit2::Zero), mRotation(Pixit::Zero), mScale(Pixit2::One)
{}

Transform::~Transform()
{}

Pixit2 const & Transform::Position() const
{
  return mPosition;
}

Pixit2 & Transform::Position()
{
  return mPosition;
}

Pixit const & Transform::Rotation() const
{
  return mRotation;
}

Pixit & Transform::Rotation()
{
  return mRotation;
}

Pixit2 const & Transform::Scale() const
{
  return mScale;
}

Pixit2 & Transform::Scale()
{
  return mScale;
}

} // namespace ZII2
