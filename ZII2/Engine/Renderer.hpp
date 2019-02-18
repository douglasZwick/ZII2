#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>

#include "ForwardDeclarations.hpp"
#include "Types.hpp"

namespace ZII2
{

class Renderer
{
public:
  Renderer();
  Renderer(Window * window, int index, uint32_t flags);
  ~Renderer();

  void SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  void Clear();
  void Render(Texture * texture,
    ZRect const * srcrect, ZRect * const dstrect,
    double angle, ZPoint const * center, ZFlip flip);
  void Present();

  void * GetHandle() const;

  bool Failed() const;
  
private:
  struct Impl;
  
  Impl * mImpl;
}; // class Renderer

} // namespace ZII2

#endif // RENDERER_H
