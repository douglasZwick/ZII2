################################################################################
# FindSDL2.cmake
#-------------------------------------------------------------------------------
# Finds the libraries, headers, and other information for SDL2.
# Once done this will define:
# + SDL2_LIBRARIES
# + SDL2_INCLUDE_DIRS
################################################################################

include(FindPackageHandleStandardArgs)

################################################################################
# Figure Out Architecture
################################################################################

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(SDL2_ARCH_SUFFIX x64)
else()
  set(SDL2_ARCH_SUFFIX x86)
endif()

################################################################################
# Configure Search Paths
################################################################################

set(SDL2_SEARCH_PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  ${SDL2_PATH}
)

set(SDL2_INCLUDE_SUFFIXES
  include
  include/SDL2
  SDL2
  SDL2/include
)

set(SDL2_LIBRARY_SUFFIXES
  lib/${SDL2_ARCH_SUFFIX}
  lib/SDL2/${SDL2_ARCH_SUFFIX}
  SDL2/lib/${SDL2_ARCH_SUFFIX}
  lib
)

################################################################################
# Find Includes
################################################################################

find_path(
  SDL2_INCLUDE_DIR
  NAMES
    SDL.h
  HINTS
    $ENV{SDL2DIR}
  PATH_SUFFIXES
    ${SDL2_INCLUDE_SUFFIXES}
  PATHS
    ${SDL2_SEARCH_PATHS}
)

################################################################################
# Find Libraries
################################################################################

find_package(Threads)

find_library(
  SDL2_LIBRARY
  NAMES
    SDL2
  HINTS
    $ENV{SDL2DIR}
  PATH_SUFFIXES
    ${SDL2_LIBRARY_SUFFIXES}
  PATHS
    ${SDL2_SEARCH_PATHS}
)

find_library(
  SDL2_LIBRARY_MAIN
  NAMES
    SDL2main
  HINTS
    $ENV{SDL2DIR}
  PATH_SUFFIXES
    ${SDL2_LIBRARY_SUFFIXES}
  PATHS
    ${SDL2_SEARCH_PATHS}
)

################################################################################
# Set Helper Variables
################################################################################

set(SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2_LIBRARY_MAIN})

################################################################################
# Report Results
################################################################################

find_package_handle_standard_args(
  SDL2
  REQUIRED_VARS
    SDL2_LIBRARIES
    SDL2_INCLUDE_DIR
)
