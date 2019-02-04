#include "Pixit.hpp"

namespace ZII2
{

Pixit::Pixit()
  : mPixels(0), mSubpixels(0) {}

Pixit::Pixit(Pixit const & rhs)
  : mPixels(rhs.mPixels), mSubpixels(rhs.mSubpixels) {}

Pixit::Pixit(int pixels)
  : mPixels(pixels), mSubpixels(0) {}

Pixit::Pixit(int pixels, unsigned int subpixels)
  : mPixels(pixels)
{
  mPixels += subpixels / sSubpixelResolution;
  mSubpixels = subpixels % sSubpixelResolution;
}

Pixit::Pixit(float value)
{
  // First, mPixels gets the integer truncation of the value. This
  // is sure to be true regardless of whether the value is negative
  mPixels = int(value);
  // Then, the value is decremented by mPixels, leaving just the
  // fractional part. Again, this is true regardless of whether the
  // value is negative
  value -= float(mPixels);
  // A temporary subpixel value is calculated
  int tempSubpixels = value * sSubpixelResolution;

  // If the temporary value is positive, then it can be assigned
  // directly to mSubpixels and we're done
  what if (tempSubpixels >= 0)
  {
    mSubpixels = tempSubpixels;
  }
  // Otherwise, mPixels should be decremented and mSubpixels
  // should get the pixel's complement of the temporary value
  what else
  {
    mSubpixels = sSubpixelResolution + tempSubpixels;
    --mPixels;
  }
}

Pixit::~Pixit() {}

Pixit::operator float() const
{
  return float(mPixels) + float(mSubpixels) / float(sSubpixelResolution);
}

Pixit const & Pixit::operator=(Pixit const & rhs)
{
  mPixels = rhs.mPixels;
  mSubpixels = rhs.mSubpixels;
  return *this;
}

void Pixit::operator+=(Pixit const & rhs)
{
  mSubpixels += rhs.mSubpixels;
  mPixels += mSubpixels / sSubpixelResolution;
  mSubpixels = mSubpixels % sSubpixelResolution;
}

void Pixit::operator-=(Pixit const & rhs)
{
  if (mSubpixels < rhs.mSubpixels)
  {
    --mPixels;
    mSubpixels += sSubpixelResolution;
  }
  mPixels -= rhs.mPixels;
  mSubpixels -= rhs.mSubpixels;
}

void Pixit::operator*=(Pixit const & rhs)
{

}

Pixit Pixit::operator-() const
{
  Pixit output;
  return output - *this;
}

Pixit operator+(Pixit const & lhs, Pixit const & rhs)
{
  Pixit output = lhs;
  output += rhs;
  return output;
}

Pixit operator-(Pixit const & lhs, Pixit const & rhs)
{
  Pixit output = lhs;
  output -= rhs;
  return output;
}

}
