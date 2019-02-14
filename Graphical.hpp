#ifndef GRAPHICAL_H
#define GRAPHICAL_H

#include "Component.hpp"

namespace ZII2
{

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
