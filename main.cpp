#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

// window dimensions
const int WindowWidth  = 1280;
const int WindowHeight = 720;

const char * ImagePath = "lea_smug.png";

// the window where the magic will happen
SDL_Window  * gWindow = NULL;
// the window's surface
SDL_Surface * gScreenSurface = NULL;
// the currently displayed image
SDL_Surface * gImage = NULL;

bool init();          // starts up SDL and creates a window
bool loadMedia();     // loads the image(s) etc
void close();         // frees the media and shuts down SDL
SDL_Surface * loadSurface(const char * path);  // loads an individual image


// returns true if initialization succeeded and false otherwise
bool init()
{
  // initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL could not be initialized. SDL Error: " << SDL_GetError() << std::endl;

    return false;
  }

  // create the window
  gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (gWindow == NULL)
  {
    std::cout << "SDL window could not be created. SDL Error: " << SDL_GetError() << std::endl;

    return false;
  }

  // initialize PNG loading
  int imgFlags = IMG_INIT_PNG;

  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    std::cout << "SDL_image could not be initialized. SDL_image Error: " << IMG_GetError() << std::endl;

    return false;
  }

  // get the window surface
  gScreenSurface = SDL_GetWindowSurface(gWindow);
  
  return true;
}


// returns true if media loading succeeded and false otherwise
bool loadMedia()
{
  gImage = loadSurface(ImagePath);

  return gImage != NULL;
}


void close()
{
  // deallocate the image surface
  SDL_FreeSurface(gImage);
  gImage = NULL;
  // destroy the window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  // quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}


SDL_Surface * loadSurface(const char * path)
{
  // the final optimized image
  SDL_Surface * optimizedSurface = NULL;

  // load the image found at the specified path
  SDL_Surface * surface = IMG_Load(path);

  if (surface == NULL)
  {
    std::cout << "Unable to load image " << path << ". SDL_image Error: " << IMG_GetError() << std::endl;

    return NULL;
  }

  // convert the surface to the screen format
  optimizedSurface = SDL_ConvertSurface(surface, gScreenSurface->format, NULL);

  if (optimizedSurface == NULL)
  {
    std::cout << "Unable to optimize image " << path << ". SDL Error: " << SDL_GetError() << std::endl;

    return NULL;
  }

  SDL_FreeSurface(surface);

  return optimizedSurface;
}


int main(int argc, char *argv[])
{
  // start up SDL and create a window
  if (!init()) return -1;
  // load the media
  if (!loadMedia()) return -1;

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

    // prepare the image rectangle
    SDL_Rect windowRect;
    windowRect.x = 0;
    windowRect.y = 0;
    SDL_GetWindowSize(gWindow, &windowRect.w, &windowRect.h);
    
    // apply the image
    SDL_BlitScaled(gImage, NULL, gScreenSurface, &windowRect);
    // update the surface
    SDL_UpdateWindowSurface(gWindow);
  }

  // free everything and close up shop
  close();

  return 0;
}
