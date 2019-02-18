#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <cstdint>

namespace ZII2
{

class Window
{
public:
  Window();
  Window(std::string title, int x, int y, int w, int h, uint32_t flags);
  ~Window();

  void * GetHandle() const;

  bool Failed() const;
  
private:
  struct Impl;
  
  Impl * mImpl;
}; // class Window

} // namespace ZII2

#endif // WINDOW_H
