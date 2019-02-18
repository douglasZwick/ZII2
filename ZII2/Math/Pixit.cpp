#include "Pixit.hpp"

namespace ZII2
{

unsigned int Pixit::sSubpixelResolution = 16;
std::string Pixit::sDelimiter = "_";
const Pixit Pixit::Zero = Pixit();
const Pixit Pixit::One = Pixit(1);

Pixit::Pixit()
  : mPixels(0), mSubpixels(0) {}

Pixit::Pixit(Pixit const & rhs)
  : mPixels(rhs.mPixels), mSubpixels(rhs.mSubpixels) {}

Pixit::Pixit(int pixels, unsigned int subpixels)
  : mPixels(pixels)
{
  mPixels += subpixels / sSubpixelResolution;
  mSubpixels = subpixels % sSubpixelResolution;
}

Pixit::Pixit(int pixels)
  : mPixels(pixels), mSubpixels(0) {}

Pixit::Pixit(float value)
{
  // First, mPixels gets the integer truncation of the value. This
  // is sure to be true regardless of whether the value is negative,
  // but it may be adjusted later
  mPixels = int(value);
  // Then, the value is decremented by mPixels, leaving just the
  // fractional part. Again, this is true regardless of whether the
  // value is negative
  value -= float(mPixels);

  // Now the subpixels need to be calculated.
  // But what if the fractional value is negative?
  if (value < 0.0f)
  {
    // In this case, we need to borrow from mPixels
    --mPixels;
    value += 1.0f;
  }

  // Finally, whether the value was negative or not, the subpixels
  // can be calculated
  mSubpixels = int(value * sSubpixelResolution);
}

Pixit::~Pixit() {}

Pixit::operator int() const
{
  return mPixels;
}

Pixit::operator bool() const
{
  return mPixels != 0 || mSubpixels != 0;
}

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
  mPixels += rhs.mPixels;
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
  float lhsFloat = float(*this);
  float rhsFloat = float(rhs);
  new (this) Pixit(lhsFloat * rhsFloat);
}

void Pixit::operator*=(float rhs)
{
  float lhsFloat = float(*this);
  new (this) Pixit(lhsFloat * rhs);
}

void Pixit::operator/=(Pixit const & rhs)
{
  float lhsFloat = float(*this);
  float rhsFloat = float(rhs);
  new (this) Pixit(lhsFloat / rhsFloat);
}

void Pixit::operator/=(float rhs)
{
  // See comments in operator*=(float)
  float lhsFloat = float(*this);
  new (this) Pixit(lhsFloat / rhs);
}

Pixit Pixit::operator-() const
{
  Pixit output = Pixit(-mPixels);
  if (mSubpixels == 0)
    return output;

  --output.mPixels;
  output.mSubpixels = sSubpixelResolution - mSubpixels;
  return output;
}

void Pixit::operator++()
{
  ++mSubpixels;
  
  if (mSubpixels >= sSubpixelResolution)
  {
    ++mPixels;
    mSubpixels -= sSubpixelResolution;
  }
}

void Pixit::operator--()
{
  if (mSubpixels == 0)
  {
    --mPixels;
    mSubpixels = sSubpixelResolution;
  }

  --mSubpixels;
}

int Pixit::GetPixels() const
{
  return mPixels;
}

int Pixit::GetSubpixels() const
{
  return mSubpixels;
}

bool Pixit::IsPos() const
{
  return mPixels > 0 || mPixels == 0 && mSubpixels > 0;
}

bool Pixit::IsZero() const
{
  return mPixels == 0 && mSubpixels == 0;
}

bool Pixit::IsNeg() const
{
  return mPixels < 0;
}

unsigned int Pixit::GetSubpixelResolution()
{
  return sSubpixelResolution;
}

bool Pixit::SetSubpixelResolution(int resolution)
{
  if (resolution < 1)
    return false;

  sSubpixelResolution = resolution;
  return true;
}

// FRIENDS AND FAMILY //
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

Pixit operator*(Pixit const & lhs, Pixit const & rhs)
{
  float lhsFloat = float(lhs);
  float rhsFloat = float(rhs);
  return Pixit(lhsFloat * rhsFloat);
}

Pixit operator*(Pixit const & lhs, float rhs)
{
  float lhsFloat = float(lhs);
  return Pixit(lhsFloat * rhs);
}

Pixit operator*(float lhs, Pixit const & rhs)
{
  return rhs * lhs;
}

Pixit operator/(Pixit const & lhs, Pixit const & rhs)
{
  float lhsFloat = float(lhs);
  float rhsFloat = float(rhs);
  return Pixit(lhsFloat / rhsFloat);
}

Pixit operator/(Pixit const & lhs, float rhs)
{
  float lhsFloat = float(lhs);
  return Pixit(lhsFloat / rhs);
}

bool operator==(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels == rhs.mPixels && lhs.mSubpixels == rhs.mSubpixels;
}

bool operator!=(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels != rhs.mPixels || lhs.mSubpixels != rhs.mSubpixels;
}

bool operator>(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels > rhs.mPixels || (lhs.mPixels == rhs.mPixels && lhs.mSubpixels > rhs.mSubpixels);
}

bool operator>=(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels > rhs.mPixels || (lhs.mPixels == rhs.mPixels && lhs.mSubpixels >= rhs.mSubpixels);
}

bool operator<(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels < rhs.mPixels || (lhs.mPixels == rhs.mPixels && lhs.mSubpixels < rhs.mSubpixels);
}

bool operator<=(Pixit const & lhs, Pixit const & rhs)
{
  return lhs.mPixels < rhs.mPixels || (lhs.mPixels == rhs.mPixels && lhs.mSubpixels <= rhs.mSubpixels);
}

std::ostream & operator<<(std::ostream & out, Pixit const & pixit)
{
  return out << pixit.mPixels << Pixit::sDelimiter << pixit.mSubpixels;
}

} // namespace ZII2
