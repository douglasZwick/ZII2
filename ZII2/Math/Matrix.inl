#ifndef MATRIX_INL
#define MATRIX_INL

#include <cassert>

#include "Matrix.hpp"

namespace ZII2
{

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

} // namespace ZII2

#endif // MATRIX_INL
