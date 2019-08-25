#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <SDL_image.h>
#include <SDL_opengl.h>

#include "Engine.hpp"
#include "Cog.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "GraphicsSystem.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "ShaderUtility.hpp"

namespace ZII2
{

struct Engine::Impl
{
  Window * Window = nullptr;
  GLuint VertexArrayID;
  GLuint ProgramID;
  GLuint VertexBuffer;
  float const VertexBufferData[9] =
  {
    -1.0f, -1.0f,  0.0f,
     1.0f, -1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
  };
};

const int Engine::sWindowWidth = 1280;
const int Engine::sWindowHeight = 720;

Texture * Engine::sLeaSmug;

//const std::string Engine::sAnimationPath = "lea_run.png";

Engine::Engine()
  : mGraphics(this), mImpl(new Impl)
{}

Engine::~Engine()
{
  delete mImpl->Window;
  delete mImpl;
}

bool Engine::InitializeOpenGL()
{
  // We still need SDL for the window
  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialized. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Let's try doing this without the SDL_SetHint call, see if it's okay

  // Now we make the winder
  uint32_t windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
  mImpl->Window = new Window("Zenith II", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    sWindowWidth, sWindowHeight, windowFlags);

  if (mImpl->Window->Failed())
  {
    std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  if (!mGraphics.Initialize(mImpl->Window))
    return false;

  glGenVertexArrays(1, &(mImpl->VertexArrayID));
  glBindVertexArray(mImpl->VertexArrayID);
  mImpl->ProgramID = ShaderUtility::Load("Shaders/BasicVertex.glsl",
    "Shaders/ConstantColorFragment.glsl");

  glGenBuffers(1, &(mImpl->VertexBuffer));
  glBindBuffer(GL_ARRAY_BUFFER, mImpl->VertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(mImpl->VertexBufferData),
    mImpl->VertexBufferData, GL_STATIC_DRAW);

  return true;
}

bool Engine::InitializeSDL()
{
  // initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialized. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // set texture filtering. "1" means linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    std::cout << "Warning: Linear texture filtering was unable to be set" << std::endl;

  // create the window
  mImpl->Window = new Window("Zenith II", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    sWindowWidth, sWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  if (mImpl->Window->Failed())
  {
    std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // initialize PNG loading
  int imgFlags = IMG_INIT_PNG;

  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    std::cout << "SDL_image could not be initialized. SDL_image Error: " << IMG_GetError() << std::endl;
    return false;
  }

  if (!mGraphics.Initialize(mImpl->Window))
    return false;

  return true;
}

int Engine::RunOpenGL()
{
  // start up SDL and OpenGL and create a window
  if (!InitializeOpenGL()) return -1;

  // main loop flag
  bool quit = false;

  double dt = 1.0 / 60.0;

  glClearColor(0.1f, 0.4f, 0.5f, 0.0f);

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

    Update(dt);
  }

  // free everything and close up shop
  CloseOpenGL();

  return 0;
}

int Engine::RunSDL()
{
  // start up SDL and create a window
  if (!InitializeSDL()) return -1;

  // main loop flag
  bool quit = false;

  //auto cogs = std::vector<Cog *>();

  //for (int i = 0; i < 360; ++i)
  //{
  //  Cog * cog = new Cog;
  //  Transform * transform = cog->Add<Transform>();
  //  Sprite * sprite = cog->Add<Sprite>();
  //  sprite->mTexture = sLeaSmug;
  //  transform->SetPositionX(Pixit(100 + i));
  //  transform->SetPositionY(Pixit(340));
  //  transform->SetRotation(Pixit(i));
  //  transform->SetScale(Pixit2(Pixit(1.0f + i * 0.01f)));

  //  mGraphics.Add(sprite);
  //  cogs.push_back(cog);
  //}

  Cog * cog = new Cog();
  Transform * transform = cog->Add<Transform>();
  Sprite * sprite = cog->Add<Sprite>();
  sprite->mTexture = sLeaSmug;
  transform->SetPosition(Pixit2::Zero);
  transform->SetRotation(Pixit::Zero);
  transform->SetScale(Pixit2(Pixit(3), Pixit(3)));
  mGraphics.Add(sprite);
  
  double dt = 1.0 / 60.0;

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

    Update(dt);
  }

  // free everything and close up shop
  CloseSDL();

  return 0;
}

void Engine::CloseOpenGL()
{
  glDeleteBuffers(1, &(mImpl->VertexBuffer));
  glDeleteVertexArrays(1, &(mImpl->VertexArrayID));
  glDeleteProgram(mImpl->ProgramID);

  mGraphics.ShutDown();
  delete mImpl->Window;
  mImpl->Window = nullptr;
  // quit the SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

void Engine::CloseSDL()
{
  mGraphics.ShutDown();
  delete mImpl->Window;
  mImpl->Window = nullptr;
  // quit the SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

Window * Engine::GetWindow() const
{
  return mImpl->Window;
}

void Engine::Update(double dt)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(mImpl->ProgramID);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, mImpl->VertexBuffer);
  glVertexAttribPointer
  (
    0,
    3,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void*)0
  );

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(0);

  SDL_GL_SwapWindow((SDL_Window*)(mImpl->Window->GetHandle()));
  //mGraphics.Update(dt);
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
