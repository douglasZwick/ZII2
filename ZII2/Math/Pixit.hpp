#ifndef PIXIT_H
#define PIXIT_H

#include <string>
#include <ostream>

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
  static std::string sDelimiter;
  static const Pixit Zero;
  static const Pixit One;

  Pixit();
  Pixit(Pixit const & rhs);
  Pixit(int pixels, unsigned int subpixels);
  explicit Pixit(int pixels);
  explicit Pixit(float value);
  ~Pixit();

  explicit operator int() const;
  explicit operator bool() const;
  explicit operator float() const;
  explicit operator double() const;

  Pixit const & operator=(Pixit const & rhs);
  void operator+=(Pixit const & rhs);
  void operator-=(Pixit const & rhs);
  void operator*=(Pixit const & rhs);
  void operator*=(float rhs);
  void operator/=(Pixit const & rhs);
  void operator/=(float rhs);
  Pixit operator-() const;
  // Perhaps controversially, ++ and -- operate on subpixels
  void operator++();
  // Perhaps controversially, ++ and -- operate on subpixels
  void operator--();

  int GetPixels() const;
  int GetSubpixels() const;

  bool IsPos() const;
  bool IsZero() const;
  bool IsNeg() const;

  static unsigned int GetSubpixelResolution();
  static bool SetSubpixelResolution(int resolution);

private:
  static unsigned int sSubpixelResolution;

  signed   int mPixels;
  unsigned int mSubpixels;

  friend Pixit operator+(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator-(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator*(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator*(Pixit const & lhs, float rhs);
  friend Pixit operator*(float lhs, Pixit const & rhs);
  friend Pixit operator/(Pixit const & lhs, Pixit const & rhs);
  friend Pixit operator/(Pixit const & lhs, float rhs);
  friend bool operator==(Pixit const & lhs, Pixit const & rhs);
  friend bool operator!=(Pixit const & lhs, Pixit const & rhs);
  friend bool operator>(Pixit const & lhs, Pixit const & rhs);
  friend bool operator>=(Pixit const & lhs, Pixit const & rhs);
  friend bool operator<(Pixit const & lhs, Pixit const & rhs);
  friend bool operator<=(Pixit const & lhs, Pixit const & rhs);
  friend std::ostream & operator<<(std::ostream & out, Pixit const & pixit);
}; // class Pixit

} // namespace ZII2

#endif // PIXIT_H
