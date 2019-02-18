#include <ZII2/Engine/Engine.hpp>

int main(int argc, char *argv[])
{
  ZII2::Engine engine;

  int status = engine.RunSDL();
  //bool success = engine.RunBGFX();

  return status;
}
