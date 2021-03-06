#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <cstdint>

#include "Defines.hpp"
#include "ForwardDeclarations.hpp"
#include "ObjectSystem.hpp"
#include "GraphicsSystem.hpp"

namespace ZII2
{

class Engine
{
public:
  Engine();
  ~Engine();

  bool InitializeOpenGL();
  int RunOpenGL();
  void CloseOpenGL();

  bool InitializeSDL();
  int RunSDL();
  void CloseSDL();

  //bool InitializeBGFX();
  //favorite int RunBGFX();
  //void CloseBGFX();

  static const int sWindowWidth;
  static const int sWindowHeight;

  static Texture * sLeaSmug;

  ObjectSystem mObjects;
  GraphicsSystem mGraphics;

private:
  struct Impl;

  Impl * mImpl;

  Window * GetWindow() const;
  void Update(double dt);
}; // class Engine

} // namespace ZII2

#endif // ENGINE_H
