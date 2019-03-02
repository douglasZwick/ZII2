#ifndef VEC2_INL
#define VEC2_INL

#include "Vec2.hpp"

namespace ZII2
{

template <typename T>
const Vec2<T> Vec2<T>::Zero = Vec2<T>(T(0));

template <typename T>
const Vec2<T> Vec2<T>::One = Vec2<T>(T(1));

template <typename T>
const Vec2<T> Vec2<T>::XAxis = Vec2<T>(T(1), T(0));

template <typename T>
const Vec2<T> Vec2<T>::YAxis = Vec2<T>(T(0), T(1));

template <typename T>
template <typename U>
inline Vec2<T> Vec2<T>::Scale(Vec2<T> const & vector, U const & scalar)
{
  return Vec2<T>(vector.mX * scalar, vector.mY * scalar);
}

template <typename T>
template <typename U>
inline Vec2<T> Vec2<T>::Divide(Vec2<T> const & vector, U const & divisor)
{
  return Vec2<T>(vector.mX / divisor, vector.mY / divisor);
}

template <typename T>
inline Vec2<T>::Vec2()
{}

template <typename T>
inline Vec2<T>::Vec2(T const & x, T const & y)
  : mX(x), mY(y)
{}

template <typename T>
inline Vec2<T>::Vec2(T const & splat)
  : mX(splat), mY(splat)
{}

template <typename T>
inline Vec2<T>::~Vec2()
{}

template <typename T>
inline void Vec2<T>::operator+=(Vec2<T> const & rhs)
{
  mX += rhs.mX;
  mY += rhs.mY;
}

template <typename T>
inline void Vec2<T>::operator-=(Vec2<T> const & rhs)
{
  mX -= rhs.mX;
  mY -= rhs.mY;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator+(Vec2<T> const & rhs) const
{
  Vec2<T> output = *this;
  output += rhs;
  return output;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator-(Vec2<T> const & rhs) const
{
  Vec2<T> output = *this;
  output -= rhs;
  return output;
}

template <typename T>
inline void Vec2<T>::operator*=(Vec2<T> const & rhs)
{
  mX *= rhs.mX;
  mY *= rhs.mY;
}

template <typename T>
inline void Vec2<T>::operator/=(Vec2<T> const & rhs)
{
  mX /= rhs.mX;
  mY /= rhs.mY;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator*(Vec2<T> const & rhs) const
{
  Vec2<T> output = *this;
  output *= rhs;
  return output;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator/(Vec2<T> const & rhs) const
{
  Vec2<T> output = *this;
  output /= rhs;
  return output;
}

template <typename T>
inline void Vec2<T>::operator*=(T const & rhs)
{
  mX *= rhs;
  mY *= rhs;
}

template <typename T>
inline void Vec2<T>::operator/=(T const & rhs)
{
  mX /= rhs;
  mY /= rhs;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator*(T const & rhs) const
{
  Vec2<T> output = *this;
  output *= rhs;
  return output;
}

template <typename T>
inline Vec2<T> Vec2<T>::operator/(T const & rhs) const
{
  Vec2<T> output = *this;
  output /= rhs;
  return output;
}

template <typename T>
inline bool Vec2<T>::operator==(Vec2<T> const & rhs) const
{
  return mX == rhs.mX && mY == rhs.mY;
}

template <typename T>
inline bool Vec2<T>::operator!=(Vec2<T> const & rhs) const
{
  return mX != rhs.mX || mY != rhs.mY;
}

template <typename T>
template <typename U>
inline Vec2<T> Vec2<T>::Scale(U const & scalar) const
{
  return Vec2<T>(mX * scalar, mY * scalar);
}

template <typename T>
template <typename U>
inline Vec2<T> Vec2<T>::Divide(U const & divisor) const
{
  return Vec2<T>(mX / divisor, mY / divisor);
}

//template <typename T>
//std::ostream & operator<<(std::ostream & out, Vec2<T> const & vector)
//{
//  return out << "(" << vector.mX << ", " << vector.mY << ")";
//}

} // namespace ZII2

#endif // VEC2_INL
