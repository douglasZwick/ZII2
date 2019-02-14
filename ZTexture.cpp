#include <iostream>
#include <string>
#include <exception>
#include <SDL_image.h>
#include "ZTexture.hpp"

namespace ZII2
{

ZTexture::ZTexture(std::string const & path, SDL_Renderer * renderer)
  : mSdlTexture(nullptr), mWidth(0), mHeight(0)
{
  if (!LoadFromFile(path, renderer))
    throw new std::exception;
}

ZTexture::~ZTexture()
{
  Free();
}

bool ZTexture::LoadFromFile(std::string const & path, SDL_Renderer * renderer)
{
  // if anything is already there, detch et
  Free();

  // this will be the final texture
  SDL_Texture * newTexture = nullptr;

  // load in the image specified by the path
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());

  if (loadedSurface == nullptr)
  {
    std::cout << "Unable to load image " << path << ". SDL_Image Error: " << IMG_GetError() << std::endl;

    return false;
  }

  // create the texture from the pixels of the surface
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  if (newTexture == nullptr)
  {
    std::cout << "Unable to create texture from " << path << ". SDL Error: " << SDL_GetError() << std::endl;

    return false;
  }

  // record the image dimensions
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;
  // detch the old loaded surface
  SDL_FreeSurface(loadedSurface);
  // set the new texture and return
  mSdlTexture = newTexture;

  return true;
}

void ZTexture::Free()
{
  // frees the texture if it exists
  if (mSdlTexture != nullptr)
  {
    SDL_DestroyTexture(mSdlTexture);
    mSdlTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
  }
}

void ZTexture::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
  SDL_SetTextureColorMod(mSdlTexture, r, g, b);
}

void ZTexture::SetAlpha(Uint8 a)
{
  SDL_SetTextureAlphaMod(mSdlTexture, a);
}

void ZTexture::SetBlendMode(SDL_BlendMode blendMode)
{
  SDL_SetTextureBlendMode(mSdlTexture, blendMode);
}

int ZTexture::GetWidth() const
{
  return mWidth;
}

int ZTexture::GetHeight() const
{
  return mHeight;
}

} // namespace ZII2
