#ifndef VEC2_H
#define VEC2_H

#include <ostream>

namespace ZII2
{

template <typename T>
class Vec2
{
public:
  static const Vec2 Zero;
  static const Vec2 One;
  static const Vec2 XAxis;
  static const Vec2 YAxis;

  T mX;
  T mY;

  template <typename U>
  static Vec2 Scale(Vec2 const & vector, U const & scalar);
  template <typename U>
  static Vec2 Divide(Vec2 const & vector, U const & divisor);

  Vec2();
  Vec2(T const & x, T const & y);
  Vec2(T const & splat);
  ~Vec2();

  void operator+=(Vec2 const & rhs);
  void operator-=(Vec2 const & rhs);
  Vec2 operator+(Vec2 const & rhs) const;
  Vec2 operator-(Vec2 const & rhs) const;
  void operator*=(Vec2 const & rhs);
  void operator/=(Vec2 const & rhs);
  Vec2 operator*(Vec2 const & rhs) const;
  Vec2 operator/(Vec2 const & rhs) const;
  void operator*=(T const & rhs);
  void operator/=(T const & rhs);
  Vec2 operator*(T const & rhs) const;
  Vec2 operator/(T const & rhs) const;
  bool operator==(Vec2 const & rhs) const;
  bool operator!=(Vec2 const & rhs) const;

  template <typename U>
  Vec2 Scale(U const & scalar) const;
  template <typename U>
  Vec2 Divide(U const & divisor) const;

  friend std::ostream & operator<<(std::ostream & out, Vec2 const & vector)
  {
    return out << "(" << vector.mX << ", " << vector.mY << ")";
  }
}; // class Vec2

typedef Vec2<float> Float2;

} // namespace ZII2

#include "Vec2.inl"

#endif // VEC2_H
