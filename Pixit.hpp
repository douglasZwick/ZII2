#ifndef PIXIT_H
#define PIXIT_H

#include <string>
#include <ostream>
#include "Defines.hpp"

namespace ZII2
{

/// A signed pixels-unsigned subpixels pair. The world's subpixel grid is NOT
/// symmetrical about the origin; that is, moving one subpixel to the left of
/// zero results in a Pixit value with -1 pixels and R - 1 subpixels, where R
/// is equal to the static subpixel resolution. This resolution is defined by
/// sSubpixelResolution, and it can be set on a per-quest basis.
class Pixit
{
public:
  Pixit();
  Pixit(Pixit const & rhs);
  Pixit(int pixels, unsigned int subpixels);
  Pixit(int pixels);
  Pixit(float value);
  ~Pixit();

  operator int() const;
  operator bool() const;
  operator float() const;

  Pixit const & operator=(Pixit const & rhs);
  void operator+=(Pixit const & rhs);
  void operator-=(Pixit const & rhs);
  void operator*=(Pixit const & rhs);
  void operator/=(Pixit const & rhs);
  Pixit operator-() const;
  // Perhaps controversially, ++ and -- operate on subpixels
  void operator++();
  // Perhaps controversially, ++ and -- operate on subpixels
  void operator--();

  bool IsPos() const;
  bool IsZero() const;
  bool IsNeg() const;

  static unsigned int sSubpixelResolution;
  static const std::string sDelimiter;
  static const Pixit Zero;
  static const Pixit One;

private:
  signed   int mPixels;
  unsigned int mSubpixels;

  friend Pixit operator+(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator-(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator*(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator/(Pixit const & lhs, Pixit const & rhs);
  friend bool operator==(Pixit const & lhs, Pixit const & rhs);
  friend bool operator!=(Pixit const & lhs, Pixit const & rhs);
  friend bool operator>(Pixit const & lhs, Pixit const & rhs);
  friend bool operator>=(Pixit const & lhs, Pixit const & rhs);
  friend bool operator<(Pixit const & lhs, Pixit const & rhs);
  friend bool operator<=(Pixit const & lhs, Pixit const & rhs);
  friend std::ostream & operator<<(std::ostream & out, Pixit const & pixit);
};

}

#endif // PIXIT_H
