#ifndef PIXIT_H
#define PIXIT_H

namespace ZII2
{

class Pixit
{
public:
  Pixit();
  Pixit(int pixels);
  Pixit(int pixels, unsigned int subpixels);
  ~Pixit();

  Pixit operator=(Pixit const & rhs);

  static const unsigned int sSubpixelResolution = 16;

private:
  signed   int mPixels;
  unsigned int mSubpixels;

  //friend Pixit operator+(Pixit const & lhs, Pixit const & rhs);
  //friend Pixit operator-(Pixit const & lhs, Pixit const & rhs);
  //friend Pixit operator*(Pixit const & lhs, Pixit const & rhs);
  //friend Pixit operator/(Pixit const & lhs, Pixit const & rhs);
};

}

#endif // PIXIT_H
