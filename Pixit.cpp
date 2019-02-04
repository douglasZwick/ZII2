#include "Pixit.hpp"

namespace ZII2
{

Pixit::Pixit()
  : mPixels(0), mSubpixels(0) {}

Pixit::Pixit(int pixels)
  : mPixels(pixels), mSubpixels(0) {}

Pixit::Pixit(int pixels, unsigned int subpixels)
  : mPixels(pixels)
{
  mPixels += subpixels / sSubpixelResolution;
  mSubpixels = subpixels % sSubpixelResolution;
}

Pixit::~Pixit() {}

Pixit Pixit::operator=(Pixit const & rhs)
{
  mPixels = rhs.mPixels;
  mSubpixels = rhs.mSubpixels;
  return *this;
}

//Pixit operator+(Pixit const & lhs, Pixit const & rhs)
//{
//  Pixit output;
//
//}

}
