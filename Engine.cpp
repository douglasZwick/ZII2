#include <iostream>
#include <cmath>
//#include <SDL_syswm.h>
#include <SDL_image.h>
//#include <bgfx/bgfx.h>
//#include <bgfx/platform.h>
#include "Engine.hpp"

namespace ZII2
{

const int Engine::sWindowWidth = 1280;
const int Engine::sWindowHeight = 720;
const Uint8 Engine::sClearR = 0x20;
const Uint8 Engine::sClearG = 0x28;
const Uint8 Engine::sClearB = 0x2A;
const Uint8 Engine::sClearA = 0xFF;

//const std::string Engine::sAnimationPath = "lea_run.png";

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::InitializeSDL()
{
  // initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialized. SDL Error: "<< SDL_GetError() << std::endl;
    return false;
  }

  // set texture filtering. "1" means linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    std::cout << "Warning: Linear texture filtering was unable to be set" << std::endl;

  // create the window
  mWindow = SDL_CreateWindow("ZII2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    sWindowWidth, sWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (mWindow == nullptr)
  {
    std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // create the vsync-enabled renderer for the window
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (mRenderer == nullptr)
  {
    std::cout << "SDL_Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // initialize the renderer color
  SDL_SetRenderDrawColor(mRenderer, sClearR, sClearG, sClearB, sClearA);
  // initialize PNG loading
  int imgFlags = IMG_INIT_PNG;

  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    std::cout << "SDL_image could not be initialized. SDL_image Error: " << IMG_GetError() << std::endl;
    return false;
  }

  return true;
}

//bool Engine::LoadMediaSDL()
//{
//  mSpriteSheet.SetRenderer(mRenderer);
//
//  if (!mSpriteSheet.LoadFromFile(sAnimationPath))
//  {
//    std::cout << "Sacre bleu, failed to load the running animation from " << sAnimationPath.c_str() << std::endl;
//    return false;
//  }
//
//  mSpriteSheet.SetScale(4, 4);
//
//  mSpriteClips[0].x =   0;
//  mSpriteClips[0].y =   0;
//  mSpriteClips[0].w =  32;
//  mSpriteClips[0].h =  32;
//
//  mSpriteClips[1].x =  32;
//  mSpriteClips[1].y =   0;
//  mSpriteClips[1].w =  32;
//  mSpriteClips[1].h =  32;
//
//  mSpriteClips[2].x =  64;
//  mSpriteClips[2].y =   0;
//  mSpriteClips[2].w =  32;
//  mSpriteClips[2].h =  32;
//
//  mSpriteClips[3].x =  96;
//  mSpriteClips[3].y =   0;
//  mSpriteClips[3].w =  32;
//  mSpriteClips[3].h =  32;
//  
//  mSpriteClips[4].x = 128;
//  mSpriteClips[4].y =   0;
//  mSpriteClips[4].w =  32;
//  mSpriteClips[4].h =  32;
//
//  mSpriteClips[5].x = 160;
//  mSpriteClips[5].y =   0;
//  mSpriteClips[5].w =  32;
//  mSpriteClips[5].h =  32;
//
//  return true;
//}

int Engine::RunSDL()
{
  // start up SDL and create a window
  if (!InitializeSDL()) return -1;
  // load the media
  //if (!LoadMediaSDL()) return -1;

  ZTexture leaSmug = ZTexture(mRenderer);
  leaSmug.LoadFromFile("lea_smug.png");
  leaSmug.SetScale(4.0f, 4.0f);

  // main loop flag
  bool quit = false;

  // event handler
  SDL_Event e;

  // keep going as long as the application is running
  while (!quit)
  {
    // handle the event queue
    while (SDL_PollEvent(&e) > 0)
    {
      switch (e.type)
      {
        // quit if the user asks for it
      case SDL_QUIT:
        quit = true;
        break;
      case SDL_KEYDOWN:
        switch (e.key.keysym.sym)
        {
        case SDLK_ESCAPE:
          quit = true;
          break;
        }
        break;
      }
    }

    // clear the screen
    SDL_SetRenderDrawColor(mRenderer, sClearR, sClearG, sClearB, sClearA);
    SDL_RenderClear(mRenderer);

    int x = (sWindowWidth - int(float(leaSmug.GetWidth()) * leaSmug.GetScaleX())) / 2;
    int y = (sWindowHeight - int(float(leaSmug.GetHeight()) * leaSmug.GetScaleY())) / 2;
    leaSmug.Render(x, y);

    // update the window
    SDL_RenderPresent(mRenderer);
  }

  // free everything and close up shop
  CloseSDL();

  return 0;
}

void Engine::CloseSDL()
{
  // free the loaded images
  //mSpriteSheet.Free();
  // destroy the window etc
  SDL_DestroyRenderer(mRenderer);
  mRenderer = nullptr;
  SDL_DestroyWindow(mWindow);
  mWindow = nullptr;
  // quit the SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

//bool Engine::InitializeBGFX()
//{
//  // start up SDL
//  if (SDL_Init(SDL_INIT_VIDEO) < 0)
//  {
//    std::cout << "Failed to initialize SDL. SDL Error: " << SDL_GetError() << std::endl;
//    return false;
//  }
//
//  // set texture filtering to linear
//  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
//    std::cout << "Warning: Linear texture filtering was unable to be set" << std::endl;
//
//  // create the window
//  mWindow = SDL_CreateWindow("ZII2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//    sWindowWidth, sWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
//
//  if (mWindow == nullptr)
//  {
//    std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
//    return false;
//  }
//
//  // now I gotta make a bgfx renderer somehow
//  // rip
//
//  SDL_SysWMinfo wmi;
//  SDL_VERSION(&wmi.version);
//  if (!SDL_GetWindowWMInfo(mWindow, &wmi))
//  {
//    std::cout << "SDL_GetWindowWMInfo failed I guess? SDL Error: " << SDL_GetError() << std::endl;
//    return false;
//  }
//
//  bgfx::Init init;
//  init.type     = bgfx::RendererType::Count;
//  init.vendorId = BGFX_PCI_ID_NONE;
//  init.resolution.width  = sWindowWidth;
//  init.resolution.height = sWindowHeight;
//  init.resolution.reset  = BGFX_RESET_VSYNC;
//  // assuming Windows only for now
//  init.platformData.ndt          = nullptr;
//  init.platformData.nwh          = wmi.info.win.window;
//  init.platformData.context      = nullptr;
//  init.platformData.backBuffer   = nullptr;
//  init.platformData.backBufferDS = nullptr;
//  bgfx::init(init);
//
//  bgfx::setDebug(BGFX_DEBUG_NONE);
//
//  bgfx::setViewClear
//  (
//    0,                                    // ViewId   _id
//    BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,  // uint16_t _flags
//    0x0000FFFF,                           // uint32_t _rgba
//    1.0f,                                 // float    _depth
//    0                                     // uint8_t  _stencil
//  );
//
//  return true;
//}
//
//int Engine::RunBGFX()
//{
//  // set things up with bgfx (which, in turn, sets things up with SDL)
//  if (!InitializeBGFX()) return -1;
//
//  // main loop flag
//  bool quit = false;
//
//  // event handler
//  SDL_Event e;
//
//  // keep going as long as the application is running
//  while (!quit)
//  {
//    // handle the event queue
//    while (SDL_PollEvent(&e) > 0)
//    {
//      switch (e.type)
//      {
//        // quit if the user asks for it
//      case SDL_QUIT:
//        quit = true;
//        break;
//      case SDL_KEYDOWN:
//        switch (e.key.keysym.sym)
//        {
//        case SDLK_ESCAPE:
//          quit = true;
//          break;
//        }
//        break;
//      }
//    }
//
//    bgfx::touch(0);
//    //bgfx::renderFrame(16);
//    bgfx::frame();
//  }
//
//  // free everything and close up shop
//  CloseBGFX();
//
//  return 0;
//}
//
//void Engine::CloseBGFX()
//{
//  bgfx::shutdown();
//
//  SDL_DestroyWindow(mWindow);
//  mWindow = nullptr;
//  // quit the SDL subsystems
//  SDL_Quit();
//}

} // namespace ZII2
