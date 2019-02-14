#include "GraphicsSystem.hpp"

namespace ZII2
{

GraphicsSystem::GraphicsSystem(Engine * engine)
  : System(engine)
{

}

GraphicsSystem::~GraphicsSystem() {}

void GraphicsSystem::Update(double dt)
{
  SDL_Renderer * renderer = mEngine->GetRenderer();

  for (auto & graphical : mGraphicals)
  {
    graphical->Render(renderer);
  }
}

} // namespace ZII2
