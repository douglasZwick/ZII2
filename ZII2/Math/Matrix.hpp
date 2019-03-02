#ifndef MATRIX_H
#define MATRIX_H

namespace ZII2
{

template <typename T>
class Matrix3x3
{
public:
  static const Matrix3x3 Zero;
  static const Matrix3x3 Identity;

  // Access order is [x][y]
  T mData[3][3];

  static Matrix3x3 Multiply(Matrix3x3 const & a, Matrix3x3 const & b);
  template <typename U>
  static Matrix3x3 Scale(Matrix3x3 const & matrix, U const & scalar);
  template <typename U>
  static Matrix3x3 Divide(Matrix3x3 const & matrix, U const & divisor);

  Matrix3x3();
  Matrix3x3(
    T t00, T t10, T t20,
    T t01, T t11, T t21,
    T t02, T t12, T t22);
  ~Matrix3x3();

  T operator()(unsigned int x, unsigned int y) const;
  T & operator()(unsigned int x, unsigned int y);
  void operator+=(Matrix3x3 const & rhs);
  void operator-=(Matrix3x3 const & rhs);
  Matrix3x3 operator+(Matrix3x3 const & rhs) const;
  Matrix3x3 operator-(Matrix3x3 const & rhs) const;
  void operator*=(T const & rhs);
  void operator/=(T const & rhs);
  Matrix3x3 operator*(T const & rhs) const;
  Matrix3x3 operator/(T const & rhs) const;
  bool operator==(Matrix3x3 const & rhs) const;
  bool operator!=(Matrix3x3 const & rhs) const;

  Matrix3x3 operator!() const;

  template <typename U>
  Matrix3x3 Scale(U const & scalar) const;
  template <typename U>
  Matrix3x3 Divide(U const & divisor) const;
  T Det() const;
  Matrix3x3 Transpose() const;

  template <typename T>
  friend Matrix3x3<T> operator*(Matrix3x3<T> const & a, Matrix3x3<T> const & b);

  //inline friend Matrix3x3<T> operator*(Matrix3x3<T> const & a, Matrix3x3<T> const & b)
  //{
  //  return Matrix3x3<T>::Multiply(a, b);
  //}
};

} // namespace ZII2

#include "Matrix.inl"

#endif // MATRIX_H
