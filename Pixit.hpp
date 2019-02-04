#ifndef PIXIT_H
#define PIXIT_H

#include "Defines.hpp"

namespace ZII2
{

class Pixit
{
public:
  Pixit();
  Pixit(Pixit const & rhs);
  Pixit(int pixels);
  Pixit(int pixels, unsigned int subpixels);
  Pixit(float value);
  ~Pixit();

  operator float() const;

  Pixit const & operator=(Pixit const & rhs);
  void operator+=(Pixit const & rhs);
  void operator-=(Pixit const & rhs);
  void operator*=(Pixit const & rhs);
  Pixit operator-() const;

  static const unsigned int sSubpixelResolution = 16;

private:
  signed   int mPixels;
  unsigned int mSubpixels;

  friend Pixit operator+(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator-(Pixit const & lhs, Pixit const & rhs);
  //friend Pixit operator*(Pixit const & lhs, Pixit const & rhs);
  //friend Pixit operator/(Pixit const & lhs, Pixit const & rhs);
};

}

#endif // PIXIT_H
