#include "Transform.hpp"

namespace ZII2
{

Transform::Transform(Cog * owner)
  : Component(owner), mPosX(0), mPosY(0),
    mAngle(0), mScaleX(1.0f), mScaleY(1.0f)
{}

Transform::~Transform() {}

} // namespace ZII2
