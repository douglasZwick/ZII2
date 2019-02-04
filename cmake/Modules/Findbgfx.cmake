include(FindPackageHandleStandardArgs)

find_package(bx REQUIRED)
find_package(bimg REQUIRED)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(BGFX_ARCH_SUFFIX x64)
else()
  set(BGFX_ARCH_SUFFIX x86)
endif()

set(BGFX_SEARCH_PATHS
# ${CMAKE_PREFIX_PATH} := D:\Modus Ponens\Libraries
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  ${BGFX_PATH}
)

set(BGFX_INCLUDE_SUFFIXES
  include
  include/bgfx
  bgfx
  bgfx/include
)

set(BGFX_LIBRARY_SUFFIXES
  lib/${BGFX_ARCH_SUFFIX}
  lib/bgfx/${BGFX_ARCH_SUFFIX}
  bgfx/lib/${BGFX_ARCH_SUFFIX}
  lib
)

find_path(
  BGFX_INCLUDE_DIR
  NAMES
    bgfx/bgfx.h
  HINTS
    $ENV{BGFXDIR}
  PATHS
    ${BGFX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BGFX_INCLUDE_SUFFIXES}
)

find_library(
  BGFX_LIBRARY_RELEASE
  NAMES
    bgfxRelease
  HINTS
    $ENV{BGFXDIR}
  PATHS
    ${BGFX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BGFX_LIBRARY_SUFFIXES}
)

find_library(
  BGFX_LIBRARY_DEBUG
  NAMES
    bgfxDebug
  HINTS
    $ENV{BGFXDIR}
  PATHS
    ${BGFX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BGFX_LIBRARY_SUFFIXES}
)

find_package_handle_standard_args(
  BGFX
  REQUIRED_VARS
    BGFX_LIBRARY_RELEASE
    BGFX_LIBRARY_DEBUG
    BGFX_INCLUDE_DIR
)
