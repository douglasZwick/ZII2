#ifndef TYPES_H
#define TYPES_H

namespace ZII2
{

struct ZRect
{
  int x, y;
  int w, h;
};

struct ZPoint
{
  int x, y;
};

enum class ZFlip
{
  None = 0x00000000,
  X    = 0x00000001,
  Y    = 0x00000002,
};

enum class ZBlendMode
{
  None     = 0x00000000,
  Blend    = 0x00000001,
  Add      = 0x00000002,
  Multiply = 0x00000004,
  Invalid  = 0x7FFFFFFF,
};

} // namespace ZII2

#endif // TYPES_H
