#ifndef ZTEXTURE_H
#define ZTEXTURE_H

#include <SDL.h>

namespace ZII2
{

class ZTexture
{
public:
  ZTexture(SDL_Renderer * renderer = nullptr);
  ~ZTexture();

  // loads image at specified path
  bool LoadFromFile(std::string path);
  // deallocates the texture
  void Free();
  // sets color
  void SetColor(Uint8 r, Uint8 g, Uint8 b);
  // sets alpha
  void SetAlpha(Uint8 a);
  // sets blend mode
  void SetBlendMode(SDL_BlendMode blendMode);
  // renders this bad boy at the given point
  void Render(int x, int y, SDL_Rect * clip = nullptr);
  void SetRenderer(SDL_Renderer * renderer);
  // gets the dimensions
  int GetWidth();
  int GetHeight();
  float GetScaleX();
  void SetScaleX(float x);
  float GetScaleY();
  void SetScaleY(float y);
  void SetScale(float x, float y);

private:
  // the actual hardware texture
  SDL_Texture * mTexture;
  // the renderer that will be passed into the Render function
  SDL_Renderer * mRenderer;
  // dimensions
  int mWidth;
  int mHeight;
  float mScaleX;
  float mScaleY;
}; // class ZTexture

} // namespace ZII2

#endif // ZTEXTURE_H
