#include <SDL.h>

#include "Window.hpp"

namespace ZII2
{

struct Window::Impl
{
  SDL_Window * Window = nullptr;
  SDL_GLContext Context = nullptr;
};

Window::Window()
  : mImpl(new Impl)
{}

Window::Window(std::string title, int x, int y, int w, int h, uint32_t flags)
  : mImpl(new Impl)
{
  mImpl->Window = SDL_CreateWindow(title.c_str(), x, y, w, h, static_cast<Uint32>(flags));
  CreateContext();
}

Window::~Window()
{
  SDL_DestroyWindow(mImpl->Window);
  delete mImpl;
}

void * Window::GetHandle() const
{
  return static_cast<void *>(mImpl->Window);
}

bool Window::Failed() const
{
  return mImpl->Window == nullptr;
}

void Window::CreateContext()
{
  mImpl->Context = SDL_GL_CreateContext(mImpl->Window);
}

} // namespace ZII2
