#ifndef ZTEXTURE_H
#define ZTEXTURE_H

#include <string>
#include <cstdint>

#include "ForwardDeclarations.hpp"
#include "Types.hpp"

namespace ZII2
{

class ZTexture
{
public:
  ZTexture();
  ZTexture(std::string const & path, Renderer * renderer);
  ZTexture(Surface * surface, Renderer * renderer);
  ~ZTexture();

  void SetColor(uint8_t r, uint8_t g, uint8_t b);
  void SetAlpha(uint8_t a);
  void SetBlendMode(ZBlendMode blendMode);
  // gets the dimensions
  int GetWidth() const;
  int GetHeight() const;
  void * GetHandle() const;

  bool Failed() const;

private:
  struct Impl;

  Impl * mImpl;

  // loads image at specified path
  bool LoadFromFile(std::string const & path, Renderer * renderer);
  bool LoadFromSurface(Surface * surface, Renderer * renderer);
  // deallocates the texture
  void Free();
}; // class ZTexture

} // namespace ZII2

#endif // ZTEXTURE_H
