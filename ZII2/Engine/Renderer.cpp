#include <SDL.h>
#include "Window.hpp"
#include "Renderer.hpp"
#include "ZTexture.hpp"

namespace ZII2
{

struct Renderer::Impl
{
  SDL_Renderer * Renderer = nullptr;
};

Renderer::Renderer()
  : mImpl(new Impl)
{}

Renderer::Renderer(Window * window, int index, uint32_t flags)
  : mImpl(new Impl)
{
  SDL_Window * sdlWindow = static_cast<SDL_Window *>(window->GetHandle());
  mImpl->Renderer = SDL_CreateRenderer(sdlWindow, index, static_cast<Uint32>(flags));
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(mImpl->Renderer);
  delete mImpl;
}

void Renderer::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  SDL_SetRenderDrawColor(
    mImpl->Renderer,
    static_cast<Uint8>(r),
    static_cast<Uint8>(g),
    static_cast<Uint8>(b),
    static_cast<Uint8>(a));
}

void Renderer::Clear()
{
  SDL_RenderClear(mImpl->Renderer);
}

void Renderer::Render(ZTexture * texture,
  ZRect const * srcrect, ZRect * const dstrect,
  double angle, ZPoint const * center, ZFlip flip)
{
  SDL_Texture * sdlTexture = static_cast<SDL_Texture *>(texture->GetHandle());
  SDL_RenderCopyEx(mImpl->Renderer, sdlTexture,
    reinterpret_cast<SDL_Rect const *>(srcrect), reinterpret_cast<SDL_Rect const *>(dstrect),
    angle, reinterpret_cast<SDL_Point const *>(center), static_cast<SDL_RendererFlip>(flip));
}

void Renderer::Present()
{
  SDL_RenderPresent(mImpl->Renderer);
}

void * Renderer::GetHandle() const
{
  return static_cast<void *>(mImpl->Renderer);
}

bool Renderer::Failed() const
{
  return mImpl->Renderer == nullptr;
}

} // namespace ZII2
