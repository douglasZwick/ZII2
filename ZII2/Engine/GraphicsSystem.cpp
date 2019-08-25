#include <iostream>

#include <SDL.h>
#include <GL/glew.h>

#include "GraphicsSystem.hpp"
#include "Engine.hpp"
#include "Graphical.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

namespace ZII2
{

struct GraphicsSystem::Impl
{
  Renderer * Renderer = nullptr;
};

GraphicsSystem::GraphicsSystem(Engine * engine)
  : System(engine),
    mClearR(0x20),
    mClearG(0x28),
    mClearB(0x2A),
    mClearA(0xFF),
    mImpl(new Impl)
{}

GraphicsSystem::~GraphicsSystem()
{
  if (mImpl != nullptr)
  {
    if (mImpl->Renderer != nullptr)
    {
      delete mImpl->Renderer;
    }
    delete mImpl;
  }
}

bool GraphicsSystem::Initialize(Window * window)
{
  glewExperimental = true;
  if (GLenum errorStatus = glewInit() != GLEW_OK)
  {
    // Problem: glewInit failed, something is seriously wrong.
    std::cout << "GLEW failed to initialize. Error: " << glewGetErrorString(errorStatus) << std::endl;
    return false;
  }

  // create the vsync-enabled renderer for the window
  mImpl->Renderer = new Renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (mImpl->Renderer->Failed())
  {
    std::cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // initialize the renderer color
  //mImpl->Renderer->SetDrawColor(mClearR, mClearG, mClearB, mClearA);

  if (!LoadImages())
  {
    std::cout << "Could not load all images." << std::endl;
    return false;
  }

  return true;
}

void GraphicsSystem::Add(Graphical * graphical)
{
  mGraphicals.push_back(graphical);
}

void GraphicsSystem::Update(double dt)
{
  Renderer * renderer = GetRenderer();
  // clear the screen
  renderer->SetDrawColor(mClearR, mClearG, mClearB, mClearA);
  renderer->Clear();

  for (auto & graphical : mGraphicals)
  {
    graphical->Render(mImpl->Renderer);
  }

  // update the window
  renderer->Present();
}

bool GraphicsSystem::LoadImages() const
{
  Renderer * renderer = GetRenderer();
  Texture * leaSmug = new Texture("lea_smug.png", renderer);

  if (leaSmug->Failed())
    return false;

  Engine::sLeaSmug = leaSmug;

  return true;
}

void GraphicsSystem::UnloadImages() const
{
  delete Engine::sLeaSmug;
  Engine::sLeaSmug = nullptr;
}

void GraphicsSystem::ShutDown()
{
  UnloadImages();

  delete mImpl->Renderer;
  mImpl->Renderer = nullptr;
  delete mImpl;
  mImpl = nullptr;
}

Renderer * GraphicsSystem::GetRenderer() const
{
  return mImpl->Renderer;
}

} // namespace ZII2
