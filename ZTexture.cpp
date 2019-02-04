#include <iostream>
#include <string>
#include <SDL_image.h>
#include "ZTexture.hpp"

ZTexture::ZTexture(SDL_Renderer * renderer)
  : mTexture(nullptr), mRenderer(renderer),
    mWidth(0), mHeight(0), mScaleX(1.0f), mScaleY(1.0f)
{}

ZTexture::~ZTexture()
{
  Free();
}

bool ZTexture::LoadFromFile(std::string path)
{
  // if anything is already there, detch et
  Free();

  // this will be the final texture
  SDL_Texture * newTexture = nullptr;

  // load in the image specified by the path
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());

  if (loadedSurface == nullptr)
  {
    std::cout << "Unable to load image " << path.c_str() << ". SDL_Image Error: " << IMG_GetError() << std::endl;

    return false;
  }

  // color key the image
  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0x00, 0xFF));
  // create the texture from the pixels of the surface
  newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);

  if (newTexture == nullptr)
  {
    std::cout << "Unable to create texture from " << path.c_str() << ". SDL Error: " << SDL_GetError() << std::endl;

    return false;
  }

  // record the image dimensions
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;
  // detch the old loaded surface
  SDL_FreeSurface(loadedSurface);
  // set the new texture and return
  mTexture = newTexture;

  return true;
}

void ZTexture::Free()
{
  // frees the texture if it exists
  if (mTexture != nullptr)
  {
    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
  }
}

void ZTexture::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
  SDL_SetTextureColorMod(mTexture, r, g, b);
}

void ZTexture::SetAlpha(Uint8 a)
{
  SDL_SetTextureAlphaMod(mTexture, a);
}

void ZTexture::SetBlendMode(SDL_BlendMode blendMode)
{
  SDL_SetTextureBlendMode(mTexture, blendMode);
}

void ZTexture::Render(int x, int y, SDL_Rect * clip)
{
  // set the rendering space and render to the screen
  SDL_Rect renderQuad = { x, y, mWidth, mHeight };
  // set the clip rendering dimensions
  if (clip != nullptr)
  {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  renderQuad.w = int(renderQuad.w * mScaleX);
  renderQuad.h = int(renderQuad.h * mScaleY);

  // render to the window
  SDL_RenderCopy(mRenderer, mTexture, clip, &renderQuad);
}

void ZTexture::SetRenderer(SDL_Renderer * renderer)
{
  mRenderer = renderer;
}

int ZTexture::GetWidth()
{
  return mWidth;
}

int ZTexture::GetHeight()
{
  return mHeight;
}

float ZTexture::GetScaleX()
{
  return mScaleX;
}

void ZTexture::SetScaleX(float x)
{
  mScaleX = x;
}

float ZTexture::GetScaleY()
{
  return mScaleY;
}

void ZTexture::SetScaleY(float y)
{
  mScaleY = y;
}

void ZTexture::SetScale(float x, float y)
{
  mScaleX = x; mScaleY = y;
}
