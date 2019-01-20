################################################################################
# FindSDL2_image.cmake
#-------------------------------------------------------------------------------
# Finds the libraries, headers, and other information for SDL2.
# Once done this will define:
# + SDL2_IMAGE_LIBRARIES
# + SDL2_IMAGE_INCLUDE_DIRS
################################################################################

include(FindPackageHandleStandardArgs)

################################################################################
# Figure Out Architecture
################################################################################

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(SDL2_IMAGE_ARCH_SUFFIX x64)
else()
  set(SDL2_IMAGE_ARCH_SUFFIX x32)
endif()

################################################################################
# Configure Search Paths
################################################################################

set(SDL2_IMAGE_SEARCH_PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  ${SDL2_IMAGE_PATH}
)

set(SDL2_IMAGE_INCLUDE_SUFFIXES
  include
  include/SDL2_image
  SDL2_image
  SDL2_image/include
)

set(SDL2_IMAGE_LIBRARY_SUFFIXES
  lib/${SDL2_IMAGE_ARCH_SUFFIX}
  lib/SDL2_image/${SDL2_IMAGE_ARCH_SUFFIX}
  SDL2_image/lib/${SDL2_IMAGE_ARCH_SUFFIX}
  lib
)

################################################################################
# Find Includes
################################################################################

find_path(
  SDL2_IMAGE_INCLUDE_DIR
  NAMES
    SDL_image.h
  HINTS
    $ENV{SDL2IMAGEDIR}
  PATH_SUFFIXES
    ${SDL2_IMAGE_INCLUDE_SUFFIXES}
  PATHS
    ${SDL2_IMAGE_SEARCH_PATHS}
)

################################################################################
# Find Libraries
################################################################################

find_library(
  SDL2_IMAGE_LIBRARY
  NAMES
    SDL2_image
  HINTS
    $ENV{SDL2IMAGEDIR}
  PATH_SUFFIXES
    ${SDL2_IMAGE_LIBRARY_SUFFIXES}
  PATHS
    ${SDL2_IMAGE_SEARCH_PATHS}
)

################################################################################
# Report Results
################################################################################

find_package_handle_standard_args(
  SDL2_IMAGE
  REQUIRED_VARS
    SDL2_IMAGE_LIBRARY
    SDL2_IMAGE_INCLUDE_DIR
)
