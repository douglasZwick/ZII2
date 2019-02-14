#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <vector>
#include "System.hpp"
#include "Graphical.hpp"

namespace ZII2
{

class GraphicsSystem : public System
{
public:
  SDL_Renderer * mRenderer;
  
  GraphicsSystem(Engine * engine);
  ~GraphicsSystem();

  void Update(double dt) override;

private:
  std::vector<Graphical *> mGraphicals;
}; // class GraphicsSystem

} // namespace ZII2

#endif // GRAPHICSSYSTEM_H
