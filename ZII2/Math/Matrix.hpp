#ifndef MATRIX_H
#define MATRIX_H

namespace ZII2
{

template <typename T>
class Matrix3x3
{
public:
  // Access order is [x][y]
  T mData[3][3];

  Matrix3x3();
  Matrix3x3(
    T t00, T t10, T t20,
    T t01, T t11, T t21,
    T t02, T t12, T t22);
  ~Matrix3x3();

  T operator()(unsigned int x, unsigned int y) const;
  T & operator()(unsigned int x, unsigned int y);
  void operator+=(Matrix3x3<T> const & rhs);
  void operator-=(Matrix3x3<T> const & rhs);
  Matrix3x3<T> operator+(Matrix3x3<T> const & rhs) const;
  Matrix3x3<T> operator-(Matrix3x3<T> const & rhs) const;
};

} // namespace ZII2

#include "Matrix.inl"

#endif // MATRIX_H
