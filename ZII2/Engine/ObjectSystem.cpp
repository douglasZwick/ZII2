#include <vector>

#include "ObjectSystem.hpp"
#include "Engine.hpp"
#include "Cog.hpp"

namespace ZII2
{

struct ObjectSystem::Impl
{
  std::vector<Cog *> mCogs;
};

ObjectSystem::ObjectSystem(Engine * engine)
  : System(engine), mImpl(new Impl)
{}

ObjectSystem::~ObjectSystem()
{
  if (mImpl != nullptr)
    delete mImpl;
}

void ObjectSystem::Add(Cog * cog)
{
  mImpl->mCogs.push_back(cog);
}

void ObjectSystem::Update(double dt)
{

}

} // namespace ZII2
