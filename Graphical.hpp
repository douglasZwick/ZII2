#ifndef GRAPHICAL_H
#define GRAPHICAL_H

#include "Component.hpp"

struct SDL_Renderer;

namespace ZII2
{

class Transform;

class Graphical : public Component
{
public:
  Transform * mTransform;
  
  Graphical(Cog * owner);
  ~Graphical();

  virtual void Render(SDL_Renderer * renderer) = 0;
}; // class Graphical

} // namespace ZII2

#endif // GRAPHICAL_H
