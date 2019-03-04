#ifndef COG_H
#define COG_H

#include <array>

#include "ForwardDeclarations.hpp"
#include "ComponentID.hpp"

namespace ZII2
{

class Cog
{
public:
  Cog();
  ~Cog();

  Cog * GetParent() const;
  //void AttachTo(Cog * newParent);
  void AttachToNoRecompute(Cog * newParent);
  void Detach();

  template <typename T>
  T * Get() const;
  template <typename T>
  T * Add();
  template <typename T>
  void Remove();

private:
  Cog * mParent;
  std::array<Component *, size_t(ComponentID::_Count)> mComponents;
}; // class Cog

template <typename T>
T * Cog::Get() const
{
  return (T *)mComponents[size_t(T::ID)];
}

template <typename T>
T * Cog::Add()
{
  T * component = Get<T>();
  if (component == nullptr)
  {
    component = new T(this);
    mComponents[size_t(T::ID)] = component;
  }
  return (T *)component;
}

template <typename T>
void Cog::Remove()
{
  T * component = Get<T>();
  if (component != nullptr)
  {
    delete component;
    mComponents[size_t(T::ID)] = nullptr;
  }
}

} // namespace ZII2

#endif // COG_H
