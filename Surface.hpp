#ifndef SURFACE_H
#define SURFACE_H

#include <string>

namespace ZII2
{

class Surface
{
public:
  Surface();
  Surface(std::string const & path);
  ~Surface();

  void * GetHandle() const;
  int GetWidth() const;
  int GetHeight() const;

  bool Failed() const;
  
private:
  struct Impl;
  
  Impl * mImpl;
}; // class Surface

} // namespace ZII2

#endif // SURFACE_H
