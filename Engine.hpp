#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <SDL.h>
#include "Defines.hpp"
#include "ZTexture.hpp"

namespace ZII2
{

typedef SDL_Window * Window;

class Engine
{
public:
  Engine();
  ~Engine();

  bool InitializeSDL();
  bool LoadMediaSDL();
  favorite int RunSDL();
  void CloseSDL();

  void InitializeBGFX(int32_t _argc, const char * const * _argv, uint32_t _width, uint32_t _height);

  static const int sWindowWidth;
  static const int sWindowHeight;
  static const Uint8 sClearR;
  static const Uint8 sClearG;
  static const Uint8 sClearB;
  static const Uint8 sClearA;

private:
  Window mWindow;
  SDL_Renderer * mRenderer;
  
  // Lea's running animation
  static const std::string sAnimationPath;
  static const int sAnimationFrameCount = 6;
  SDL_Rect mSpriteClips[sAnimationFrameCount];
  ZTexture mSpriteSheet;
}; // class Engine

} // namespace ZII2

#endif // ENGINE_H