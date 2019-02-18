#include <SDL.h>

#include "Window.hpp"

namespace ZII2
{

struct Window::Impl
{
  SDL_Window * Window = nullptr;
};

Window::Window()
  : mImpl(new Impl)
{}

Window::Window(std::string title, int x, int y, int w, int h, uint32_t flags)
  : mImpl(new Impl)
{
  mImpl->Window = SDL_CreateWindow(title.c_str(), x, y, w, h, static_cast<Uint32>(flags));
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

} // namespace ZII2
