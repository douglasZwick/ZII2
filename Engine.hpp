#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <SDL.h>
#include "Defines.hpp"
#include "GraphicsSystem.hpp"
#include "ZTexture.hpp"

namespace ZII2
{

class Engine
{
public:
  Engine();
  ~Engine();

  bool InitializeSDL();
  bool LoadResources();
  int RunSDL();
  void CloseSDL();
  SDL_Window * GetWindow() const;
  SDL_Renderer * GetRenderer() const;

  //bool InitializeBGFX();
  //favorite int RunBGFX();
  //void CloseBGFX();

  static const int sWindowWidth;
  static const int sWindowHeight;
  static const Uint8 sClearR;
  static const Uint8 sClearG;
  static const Uint8 sClearB;
  static const Uint8 sClearA;

  static ZTexture * sLeaSmug;

private:
  GraphicsSystem mGraphics;
  SDL_Window * mWindow;
  SDL_Renderer * mRenderer;
}; // class Engine

} // namespace ZII2

#endif // ENGINE_H
