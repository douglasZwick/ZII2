#ifndef MATRIX_INL
#define MATRIX_INL

#include <cassert>
#include <cmath>

#include "Matrix.hpp"

namespace ZII2
{

template <typename T>
const Matrix3x3<T> Matrix3x3<T>::Zero = Matrix3x3<T>(
  T(0), T(0), T(0),
  T(0), T(0), T(0),
  T(0), T(0), T(0));

template <typename T>
const Matrix3x3<T> Matrix3x3<T>::Identity = Matrix3x3<T>(
  T(1), T(0), T(0),
  T(0), T(1), T(0),
  T(0), T(0), T(1));

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::Multiply(Matrix3x3<T> const & a,
  Matrix3x3<T> const & b)
{
  Matrix3x3<T> output;
  output(0, 0) = a(0,0)*b(0,0) + a(1,0)*b(0,1) + a(2,0)*b(0,2);
  output(1, 0) = a(0,0)*b(1,0) + a(1,0)*b(1,1) + a(2,0)*b(1,2);
  output(2, 0) = a(0,0)*b(2,0) + a(1,0)*b(2,1) + a(2,0)*b(2,2);

  output(0, 1) = a(0,1)*b(0,0) + a(1,1)*b(0,1) + a(2,1)*b(0,2);
  output(1, 1) = a(0,1)*b(1,0) + a(1,1)*b(1,1) + a(2,1)*b(1,2);
  output(2, 1) = a(0,1)*b(2,0) + a(1,1)*b(2,1) + a(2,1)*b(2,2);

  output(0, 2) = a(0,2)*b(0,0) + a(1,2)*b(0,1) + a(2,2)*b(0,2);
  output(1, 2) = a(0,2)*b(1,0) + a(1,2)*b(1,1) + a(2,2)*b(1,2);
  output(2, 2) = a(0,2)*b(2,0) + a(1,2)*b(2,1) + a(2,2)*b(2,2);

  return output;
}

template <typename T>
template <typename U>
inline Matrix3x3<T> Matrix3x3<T>::Scale(Matrix3x3<T> const & matrix, U const & scalar)
{
  return Matrix3x3(
    matrix(0, 0) * scalar, matrix(1, 0) * scalar, matrix(2, 0) * scalar,
    matrix(0, 1) * scalar, matrix(1, 1) * scalar, matrix(2, 1) * scalar,
    matrix(0, 2) * scalar, matrix(1, 2) * scalar, matrix(2, 2) * scalar);
}

template <typename T>
template <typename U>
inline Matrix3x3<T> Matrix3x3<T>::Divide(Matrix3x3<T> const & matrix, U const & divisor)
{
  return Matrix3x3(
    matrix(0, 0) / divisor, matrix(1, 0) / divisor, matrix(2, 0) / divisor,
    matrix(0, 1) / divisor, matrix(1, 1) / divisor, matrix(2, 1) / divisor,
    matrix(0, 2) / divisor, matrix(1, 2) / divisor, matrix(2, 2) / divisor);
}

template <typename T>
inline Matrix3x3<T>::Matrix3x3()
{}

template <typename T>
inline Matrix3x3<T>::Matrix3x3(
  T t00, T t10, T t20,
  T t01, T t11, T t21,
  T t02, T t12, T t22)
  : mData{
    {t00, t01, t02},
    {t10, t11, t12},
    {t20, t21, t22} }
{}

template <typename T>
inline Matrix3x3<T>::~Matrix3x3()
{}

template <typename T>
inline T Matrix3x3<T>::operator()(unsigned int x, unsigned int y) const
{
  assert(x < 3 && y < 3);
  return mData[x][y];
}

template <typename T>
inline T & Matrix3x3<T>::operator()(unsigned int x, unsigned int y)
{
  assert(x < 3 && y < 3);
  return mData[x][y];
}

template <typename T>
inline void Matrix3x3<T>::operator+=(Matrix3x3<T> const & rhs)
{
  Matrix3x3<T> & self = *this;
  self(0, 0) += rhs(0, 0); self(1, 0) += rhs(1, 0); self(2, 0) += rhs(2, 0);
  self(0, 1) += rhs(0, 1); self(1, 1) += rhs(1, 1); self(2, 1) += rhs(2, 1);
  self(0, 2) += rhs(0, 2); self(1, 2) += rhs(1, 2); self(2, 2) += rhs(2, 2);
}

template <typename T>
inline void Matrix3x3<T>::operator-=(Matrix3x3<T> const & rhs)
{
  Matrix3x3<T> & self = *this;
  self(0, 0) -= rhs(0, 0); self(1, 0) -= rhs(1, 0); self(2, 0) -= rhs(2, 0);
  self(0, 1) -= rhs(0, 1); self(1, 1) -= rhs(1, 1); self(2, 1) -= rhs(2, 1);
  self(0, 2) -= rhs(0, 2); self(1, 2) -= rhs(1, 2); self(2, 2) -= rhs(2, 2);
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::operator+(Matrix3x3<T> const & rhs) const
{
  Matrix3x3<T> output = *this;
  output += rhs;
  return output;
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::operator-(Matrix3x3<T> const & rhs) const
{
  Matrix3x3<T> output = *this;
  output -= rhs;
  return output;
}

template <typename T>
inline void Matrix3x3<T>::operator*=(T const & rhs)
{
  Matrix3x3<T> & self = *this;
  self(0, 0) *= rhs; self(1, 0) *= rhs; self(2, 0) *= rhs;
  self(0, 1) *= rhs; self(1, 1) *= rhs; self(2, 1) *= rhs;
  self(0, 2) *= rhs; self(1, 2) *= rhs; self(2, 2) *= rhs;
}

template <typename T>
inline void Matrix3x3<T>::operator/=(T const & rhs)
{
  Matrix3x3<T> & self = *this;
  self(0, 0) /= rhs; self(1, 0) /= rhs; self(2, 0) /= rhs;
  self(0, 1) /= rhs; self(1, 1) /= rhs; self(2, 1) /= rhs;
  self(0, 2) /= rhs; self(1, 2) /= rhs; self(2, 2) /= rhs;
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::operator*(T const & rhs) const
{
  Matrix3x3<T> output = *this;
  output *= rhs;
  return output;
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::operator/(T const & rhs) const
{
  Matrix3x3<T> output = *this;
  output /= rhs;
  return output;
}

template <typename T>
inline bool Matrix3x3<T>::operator==(Matrix3x3<T> const & rhs) const
{
  Matrix3x3<T> const & self = *this;
  return self(0, 0) == rhs(0, 0) && self(1, 0) == rhs(1, 0) && self(2, 0) == rhs(2, 0) &&
         self(0, 1) == rhs(0, 1) && self(1, 1) == rhs(1, 1) && self(2, 1) == rhs(2, 1) &&
         self(0, 2) == rhs(0, 2) && self(1, 2) == rhs(1, 2) && self(2, 2) == rhs(2, 2);
}

template <typename T>
inline bool Matrix3x3<T>::operator!=(Matrix3x3<T> const & rhs) const
{
  Matrix3x3<T> const & self = *this;
  return self(0, 0) != rhs(0, 0) || self(1, 0) != rhs(1, 0) || self(2, 0) != rhs(2, 0) ||
         self(0, 1) != rhs(0, 1) || self(1, 1) != rhs(1, 1) || self(2, 1) != rhs(2, 1) ||
         self(0, 2) != rhs(0, 2) || self(1, 2) != rhs(1, 2) || self(2, 2) != rhs(2, 2);
}

template <typename T>
inline Vec2<T> Matrix3x3<T>::operator*(Vec2<T> const & rhs) const
{
  T x = mData[0][0] * rhs.mX + mData[1][0] * rhs.mY + mData[2][0];
  T y = mData[0][1] * rhs.mX + mData[1][1] * rhs.mY + mData[2][1];
  return Vec2<T>(x, y);
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::operator!() const
{
  return Transpose();
}

template <typename T>
template <typename U>
inline Matrix3x3<T> Matrix3x3<T>::Scale(U const & scalar) const
{
  return Matrix3x3(
    mData[0][0] * scalar, mData[1][0] * scalar, mData[2][0] * scalar,
    mData[0][1] * scalar, mData[1][1] * scalar, mData[2][1] * scalar,
    mData[0][2] * scalar, mData[1][2] * scalar, mData[2][2] * scalar);
}

template <typename T>
template <typename U>
inline Matrix3x3<T> Matrix3x3<T>::Divide(U const & divisor) const
{
  return Matrix3x3(
    mData[0][0] / divisor, mData[1][0] / divisor, mData[2][0] / divisor,
    mData[0][1] / divisor, mData[1][1] / divisor, mData[2][1] / divisor,
    mData[0][2] / divisor, mData[1][2] / divisor, mData[2][2] / divisor);
}

template <typename T>
inline T Matrix3x3<T>::Det() const
{
  return mData[0][0] * mData[1][1] * mData[2][2] +
         mData[1][0] * mData[2][1] * mData[0][2] +
         mData[2][0] * mData[0][1] * mData[1][2] -
         mData[2][0] * mData[1][1] * mData[0][2] -
         mData[1][0] * mData[0][1] * mData[2][2] -
         mData[0][0] * mData[2][1] * mData[1][2];
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::Transpose() const
{
  return Matrix3x3<T>(
    mData[0][0], mData[0][1], mData[0][2],
    mData[1][0], mData[1][1], mData[1][2],
    mData[2][0], mData[2][1], mData[2][2]);
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::TranslationMatrix(Vec2<T> const & translation)
{
  T x = translation.mX;
  T y = translation.mY;
  T t0 = T(0);
  T t1 = T(1);

  return Matrix3x3<T>(
    t1, t0, x,
    t0, t1, y,
    t0, t0, t1);
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::RotationMatrix(T const & rotation)
{
  float fRotation = float(rotation);
  T tCos = T(cosf(fRotation));
  T tSin = T(sinf(fRotation));
  T t0 = T(0);
  T t1 = T(1);

  return Matrix3x3<T>(
    tCos, -tSin,  t0,
    tSin,  tCos,  t0,
    t0,    t0,    t1);
}

template <typename T>
inline Matrix3x3<T> Matrix3x3<T>::ScaleMatrix(Vec2<T> const & scale)
{
  T x = scale.mX;
  T y = scale.mY;
  T t0 = T(0);
  T t1 = T(1);

  return Matrix3x3<T>(
    x,  t0, t0,
    t0, y,  t0,
    t0, t0, t1);
}

template <typename T>
inline Matrix3x3<T> operator*(Matrix3x3<T> const & a,
  Matrix3x3<T> const & b)
{
  return Matrix3x3<T>::Multiply(a, b);
}

} // namespace ZII2

#endif // MATRIX_INL
