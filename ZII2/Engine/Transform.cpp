#include "Transform.hpp"
#include "Cog.hpp"

namespace ZII2
{

const ComponentID Transform::ID = ComponentID::Transform;

Transform::Transform(Cog * owner)
  : Component(owner), mPosition(Pixit2::Zero),
  mRotation(Pixit::Zero), mScale(Pixit2::One)
  //mDirty(false), mLocalMatrix(Matrix3x3<Pixit>::Identity)
{}

Transform::~Transform()
{}

//void Transform::Update()
//{
//  if (!mDirty) return;
//
//  mDirty = false;
//
//  Matrix3x3<Pixit> translationM = Matrix3x3<Pixit>::TranslationMatrix(mPosition);
//  Matrix3x3<Pixit> rotationM = Matrix3x3<Pixit>::RotationMatrix(mRotation);
//  Matrix3x3<Pixit> scaleM = Matrix3x3<Pixit>::ScaleMatrix(mScale);
//  mLocalMatrix = translationM * (rotationM * scaleM);
//}

Pixit2 const & Transform::GetPosition() const
{
  return mPosition;
}

void Transform::SetPosition(Pixit2 const & position)
{
  mPosition = position;
  //mDirty = true;
}

void Transform::SetPositionX(Pixit const & x)
{
  Pixit2 position = mPosition;
  position.mX = x;
  SetPosition(position);
}

void Transform::SetPositionY(Pixit const & y)
{
  Pixit2 position = mPosition;
  position.mY = y;
  SetPosition(position);
}

Pixit const & Transform::GetRotation() const
{
  return mRotation;
}

void Transform::SetRotation(Pixit const & rotation)
{
  mRotation = rotation;
  //mDirty = true;
}

Pixit2 const & Transform::GetScale() const
{
  return mScale;
}

void Transform::SetScale(Pixit2 const & scale)
{
  mScale = scale;
  //mDirty = true;
}

void Transform::SetScaleX(Pixit const & x)
{
  Pixit2 scale = mScale;
  scale.mX = x;
  SetScale(scale);
}

void Transform::SetScaleY(Pixit const & y)
{
  Pixit2 scale = mScale;
  scale.mY = y;
  SetScale(scale);
}

//Pixit2 Transform::TransformPoint(Pixit2 const & point) const
//{
//  return mLocalMatrix * point;
//}

} // namespace ZII2
