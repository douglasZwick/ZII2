#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <vector>
#include <cstdint>

#include "ForwardDeclarations.hpp"
#include "System.hpp"

namespace ZII2
{

class GraphicsSystem : public System
{
public:
  uint8_t mClearR;
  uint8_t mClearG;
  uint8_t mClearB;
  uint8_t mClearA;

  GraphicsSystem(Engine * engine);
  ~GraphicsSystem();

  bool Initialize(Window * window);
  void Add(Graphical * graphical);
  void Update(double dt) override;
  bool LoadImages() const;
  void UnloadImages() const;
  void ShutDown();

private:
  struct Impl;

  Impl * mImpl;
  std::vector<Graphical *> mGraphicals;
  
  void GenerateQuad();
  void PrepareShaders();
  Renderer * GetRenderer() const;
}; // class GraphicsSystem

} // namespace ZII2

#endif // GRAPHICSSYSTEM_H
