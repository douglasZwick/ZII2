#include <bgfx/bgfx.h>
#include <bimg/bimg.h>
#include <bx/bx.h>
#include "Engine.hpp"

int main(int argc, char *argv[])
{
  ZII2::Engine engine;

  int status = engine.RunSDL();

  return status;
}
