#ifndef TRANFORM_H
#define TRANFORM_H

#include "ForwardDeclarations.hpp"
#include "Component.hpp"
#include "ZII2/Math/Pixit.hpp"
#include "ZII2/Math/Matrix.hpp"
#include "Types.hpp"

namespace ZII2
{
class Transform : public Component
{
public:
  static const ComponentID ID;

  Transform(Cog * owner);
  ~Transform();

  //void Update();

  Pixit2 const & GetPosition() const;
  void SetPosition(Pixit2 const & position);
  void SetPositionX(Pixit const & x);
  void SetPositionY(Pixit const & y);
  Pixit const & GetRotation() const;
  void SetRotation(Pixit const & rotation);
  Pixit2 const & GetScale() const;
  void SetScale(Pixit2 const & scale);
  void SetScaleX(Pixit const & x);
  void SetScaleY(Pixit const & y);

  //Pixit2 TransformPoint(Pixit2 const & point) const;

private:
  Pixit2 mPosition;
  Pixit mRotation;
  Pixit2 mScale;
  //bool mDirty;
  //Matrix3x3<Pixit> mLocalMatrix;
}; // class Transform

} // namespace ZII2

#endif // TRANFORM_H
