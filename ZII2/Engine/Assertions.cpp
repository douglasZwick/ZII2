#include <cstdint>
#include <cstddef>
#include <type_traits>

#include <SDL.h>

#include "Types.hpp"

namespace ZII2
{

#define ZSizeAssert(mytype, theirtype) \
  static_assert(sizeof(mytype) == sizeof(theirtype), \
    #theirtype " ain't what it used to be -- its size changed!");
#define ZSignAssert(mytype, theirtype) \
  static_assert(std::is_signed<mytype>::value == std::is_signed<theirtype>::value, \
    #theirtype " ain't what it used to be -- its signedness changed!");

#define ZPodAssert(mytype, theirtype) \
  ZSizeAssert(mytype, theirtype) \
  ZSignAssert(mytype, theirtype)

//static_assert(sizeof(uint8_t) == sizeof(Uint8),
//  "Uint8 ain't what it used to be -- its size changed!");
//static_assert(std::is_signed<uint8_t>::value == std::is_signed<Uint8>::value,
//  "Uint8 ain't what it used to be -- its signedness changed!");

ZPodAssert(uint8_t, Uint8)
ZPodAssert(uint32_t, Uint32)

ZSizeAssert(ZRect, SDL_Rect)
static_assert(
  sizeof(ZRect::x) == sizeof(SDL_Rect::x) &&
  sizeof(ZRect::y) == sizeof(SDL_Rect::y) &&
  sizeof(ZRect::w) == sizeof(SDL_Rect::w) &&
  sizeof(ZRect::h) == sizeof(SDL_Rect::h),
  "SDL_Rect ain't what it used to be -- some of its members changed size!");
static_assert(
  offsetof(ZRect, x) == offsetof(SDL_Rect, x) &&
  offsetof(ZRect, y) == offsetof(SDL_Rect, y) &&
  offsetof(ZRect, w) == offsetof(SDL_Rect, w) &&
  offsetof(ZRect, h) == offsetof(SDL_Rect, h),
  "SDL_Rect ain't what it used to be -- some of its members moved around!");

} // namespace ZII2
