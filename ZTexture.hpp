#ifndef ZTEXTURE_H
#define ZTEXTURE_H

#include <string>
#include <SDL.h>

namespace ZII2
{

class ZTexture
{
public:
  // the actual hardware texture
  SDL_Texture * mSdlTexture;

  ZTexture(std::string const & path, SDL_Renderer * renderer);
  ~ZTexture();

  void SetColor(Uint8 r, Uint8 g, Uint8 b);
  void SetAlpha(Uint8 a);
  void SetBlendMode(SDL_BlendMode blendMode);
  // gets the dimensions
  int GetWidth() const;
  int GetHeight() const;

private:
  // dimensions
  int mWidth;
  int mHeight;

  // loads image at specified path
  bool LoadFromFile(std::string const & path, SDL_Renderer * renderer);
  // deallocates the texture
  void Free();
}; // class ZTexture

} // namespace ZII2

#endif // ZTEXTURE_H
