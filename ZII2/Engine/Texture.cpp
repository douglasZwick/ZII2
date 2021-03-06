#include <iostream>
#include <string>

#include <SDL_image.h>

#include "Texture.hpp"
#include "Surface.hpp"
#include "Renderer.hpp"

namespace ZII2
{

struct Texture::Impl
{
  SDL_Texture * Texture = nullptr;
  int Width = -1;
  int Height = -1;
};

Texture::Texture()
  : mImpl(new Impl)
{}

Texture::Texture(std::string const & path, Renderer * renderer)
  : mImpl(new Impl)
{
  LoadFromFile(path, renderer);
}

Texture::Texture(Surface * surface, Renderer * renderer)
  : mImpl(new Impl)
{
  LoadFromSurface(surface, renderer);
}

Texture::~Texture()
{
  Free();
}

bool Texture::LoadFromFile(std::string const & path, Renderer * renderer)
{
  // if anything is already there, detch et
  Free();

  Surface * surface = new Surface(path);

  if (surface->Failed())
  {
    std::cout << "Unable to load image " << path << ". SDL_Image Error: " << IMG_GetError() << std::endl;
    return false;
  }

  // create the texture from the pixels of the surface
  if (!LoadFromSurface(surface, renderer))
    return false;

  // record the image dimensions
  mImpl->Width = surface->GetWidth();
  mImpl->Height = surface->GetHeight();
  // detch the old loaded surface
  delete surface;

  return true;
}

bool Texture::LoadFromSurface(Surface * surface, Renderer * renderer)
{
  SDL_Renderer * sdlRenderer = static_cast<SDL_Renderer *>(renderer->GetHandle());
  SDL_Surface * sdlSurface = static_cast<SDL_Surface *>(surface->GetHandle());
  mImpl->Texture = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);

  if (Failed())
  {
    std::cout << "Unable to create texture from given surface. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}

void Texture::Free()
{
  // frees the texture if it exists
  if (mImpl->Texture != nullptr)
  {
    SDL_DestroyTexture(mImpl->Texture);
    mImpl->Texture = nullptr;
    mImpl->Width = -1;
    mImpl->Height = -1;
  }
}

void Texture::SetColor(uint8_t r, uint8_t g, uint8_t b)
{
  SDL_SetTextureColorMod(
    mImpl->Texture, 
    static_cast<Uint8>(r),
    static_cast<Uint8>(g),
    static_cast<Uint8>(b));
}

void Texture::SetAlpha(uint8_t a)
{
  SDL_SetTextureAlphaMod(
    mImpl->Texture,
    static_cast<Uint8>(a));
}

void Texture::SetBlendMode(ZBlendMode blendMode)
{
  SDL_SetTextureBlendMode(
    mImpl->Texture,
    static_cast<SDL_BlendMode>(blendMode));
}

int Texture::GetWidth() const
{
  return mImpl->Width;
}

int Texture::GetHeight() const
{
  return mImpl->Height;
}

void * Texture::GetHandle() const
{
  return static_cast<void *>(mImpl->Texture);
}

bool Texture::Failed() const
{
  return mImpl->Texture == nullptr;
}

} // namespace ZII2
