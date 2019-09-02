#ifndef TYPES_H
#define TYPES_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "ZII2/Math/Pixit.hpp"
#include "ZII2/Math/Vec2.hpp"

namespace ZII2
{

typedef Vec2<float> Float2;
typedef Vec2<Pixit> Pixit2;

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

struct Vertex
{
  glm::vec3 Position;
  glm::vec2 Uv;
};

} // namespace ZII2

#endif // TYPES_H
