################################################################################
# ZII2 - CMakeLists.txt
# Project configuration for ZII2.
################################################################################
cmake_minimum_required(VERSION 3.13)
project(ZII2 CXX)

################################################################################
# Turn On Project Folders
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# **Reminders:**
# CMAKE_PREFIX_PATH
#   This is an environment variable that must be set by the developer.
#   It is supposed to tell CMake unambiguously where to find development files.
# CMAKE_MODULE_PATH:
#   This variable tells find_package where to look for Find*.cmake modules.
#   The developer shouldn't need to change this, we use it to tell CMake.
################################################################################
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
# find_package(bgfx REQUIRED)
find_package(googletest)

################################################################################
# Build Practice Executable
################################################################################

add_library(
  ZII2_Engine
  Defines.hpp
  ForwardDeclarations.hpp
  Types.hpp
  Window.cpp
  Window.hpp
  Renderer.cpp
  Renderer.hpp
  Engine.cpp
  Engine.hpp
  System.cpp
  System.hpp
  GraphicsSystem.cpp
  GraphicsSystem.hpp
  Cog.cpp
  Cog.hpp
  Component.cpp
  Component.hpp
  Transform.cpp
  Transform.hpp
  Graphical.cpp
  Graphical.hpp
  Sprite.cpp
  Sprite.hpp
  Color.cpp
  Color.hpp
  Pixit.cpp
  Pixit.hpp
  ZTexture.cpp
  ZTexture.hpp
  Surface.cpp
  Surface.hpp
  Assertions.cpp
)

add_library(
  ZII2_Math
  ZMath.cpp
  ZMath.hpp
)

add_executable(
  Practice
  main.cpp
)

target_link_libraries(ZII2_Engine ZII2_Math)
target_link_libraries(Practice ZII2_Engine)

option(ZII2_BUILD_TESTS
  "Do you want to build unit tests?"
  OFF
)

if(ZII2_BUILD_TESTS)
  add_executable(
    ZII2_Tests
    gtest_runner.cpp
    ZII2_Tests_Main.cpp
  )
  
  target_link_libraries(ZII2_Tests ZII2_Engine)
  
  target_include_directories(
    ZII2_Tests
    PRIVATE
      ${GOOGLETEST_INCLUDE_DIR}
  )
  
  target_link_libraries(
    ZII2_Tests
    debug
      ${GOOGLETEST_LIBRARIES_DEBUG}
  )
  
  target_link_libraries(
    ZII2_Tests
    optimized
      ${GOOGLETEST_LIBRARIES_RELEASE}
  )
endif()

target_include_directories(
  ZII2_Engine
  PRIVATE
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    # ${BGFX_INCLUDE_DIR}
    # ${BIMG_INCLUDE_DIR}
    # ${BX_INCLUDE_DIRS}
)

target_link_libraries(
  ZII2_Engine
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARY}
)

# target_link_libraries(
#   ZII2_Engine
#   debug
#     ${BGFX_LIBRARY_DEBUG}
#     ${BIMG_LIBRARY_DEBUG}
#     ${BX_LIBRARY_DEBUG}
# )

# target_link_libraries(
#   ZII2_Engine
#   optimized
#     ${BGFX_LIBRARY_RELEASE}
#     ${BIMG_LIBRARY_RELEASE}
#     ${BX_LIBRARY_RELEASE}
# )
