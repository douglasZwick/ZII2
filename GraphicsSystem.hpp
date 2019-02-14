#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <vector>
#include "System.hpp"

struct SDL_Renderer;

namespace ZII2
{

class Graphical;

class GraphicsSystem : public System
{
public:
  SDL_Renderer * mRenderer;
  
  GraphicsSystem(Engine * engine);
  ~GraphicsSystem();

  void Add(Graphical * graphical);
  void Update(double dt) override;

private:
  std::vector<Graphical *> mGraphicals;
}; // class GraphicsSystem

} // namespace ZII2

#endif // GRAPHICSSYSTEM_H
