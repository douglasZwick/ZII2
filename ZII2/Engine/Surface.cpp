#include <SDL.h>
#include <SDL_image.h>

#include "Surface.hpp"

namespace ZII2
{

struct Surface::Impl
{
  SDL_Surface * Surface = nullptr;
};

Surface::Surface()
  : mImpl(new Impl)
{}

Surface::Surface(std::string const & path)
  : mImpl(new Impl)
{
  mImpl->Surface = IMG_Load(path.c_str());
}

Surface::~Surface()
{
  SDL_FreeSurface(mImpl->Surface);
  delete mImpl;
}

void * Surface::GetHandle() const
{
  return static_cast<void *>(mImpl->Surface);
}

int Surface::GetWidth() const
{
  return mImpl->Surface->w;
}

int Surface::GetHeight() const
{
  return mImpl->Surface->h;
}

bool Surface::Failed() const
{
  return mImpl->Surface == nullptr;
}

} // namespace ZII2
