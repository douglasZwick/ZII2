#include "GraphicsSystem.hpp"
#include "Engine.hpp"
#include "Graphical.hpp"
#include <SDL.h>

namespace ZII2
{

GraphicsSystem::GraphicsSystem(Engine * engine)
  : System(engine)
{

}

GraphicsSystem::~GraphicsSystem() {}

void GraphicsSystem::Add(Graphical * graphical)
{
  mGraphicals.push_back(graphical);
}

void GraphicsSystem::Update(double dt)
{
  SDL_Renderer * renderer = mEngine->GetRenderer();

  for (auto & graphical : mGraphicals)
  {
    graphical->Render(renderer);
  }
}

} // namespace ZII2
