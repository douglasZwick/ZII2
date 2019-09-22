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
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
# find_package(bgfx REQUIRED)
find_package(googletest)

set(ZII2_INCLUDE_DIR ${CMAKE_SOURCE_DIR})

################################################################################
# Build Practice Executable
################################################################################

set(ZII_ENGINE_SOURCE
  ZII2/Engine/Engine.cpp
  ZII2/Engine/Engine.hpp
  ZII2/Engine/System.cpp
  ZII2/Engine/System.hpp
  ZII2/Engine/ObjectSystem.cpp
  ZII2/Engine/ObjectSystem.hpp
  ZII2/Engine/GraphicsSystem.cpp
  ZII2/Engine/GraphicsSystem.hpp
  ZII2/Engine/Cog.cpp
  ZII2/Engine/Cog.hpp
  ZII2/Engine/ComponentID.hpp
  ZII2/Engine/Component.cpp
  ZII2/Engine/Component.hpp
  ZII2/Engine/Transform.cpp
  ZII2/Engine/Transform.hpp
  ZII2/Engine/Graphical.cpp
  ZII2/Engine/Graphical.hpp
  ZII2/Engine/Sprite.cpp
  ZII2/Engine/Sprite.hpp
  ZII2/Engine/Texture.cpp
  ZII2/Engine/Texture.hpp
  ZII2/Engine/Surface.cpp
  ZII2/Engine/Surface.hpp
  ZII2/Engine/Window.cpp
  ZII2/Engine/Window.hpp
  ZII2/Engine/Renderer.cpp
  ZII2/Engine/Renderer.hpp
  ZII2/Engine/Color.cpp
  ZII2/Engine/Color.hpp
  ZII2/Engine/Defines.hpp
  ZII2/Engine/ForwardDeclarations.hpp
  ZII2/Engine/Types.hpp
  ZII2/Engine/Assertions.cpp
  ZII2/Engine/ShaderUtility.hpp
  ZII2/Engine/ShaderUtility.cpp
)

set(ZII_MATH_SOURCE
  ZII2/Math/Math.cpp
  ZII2/Math/Math.hpp
  ZII2/Math/Pixit.cpp
  ZII2/Math/Pixit.hpp
  ZII2/Math/Matrix.inl
  ZII2/Math/Matrix.hpp
  ZII2/Math/Vec2.inl
  ZII2/Math/Vec2.hpp
)

add_library(
  ZII2_Engine
  ${ZII_ENGINE_SOURCE}
)

add_library(
  ZII2_Math
  ${ZII_MATH_SOURCE}
)

add_executable(
  Practice
  ZII2/Game/main.cpp
)

target_link_libraries(
  #[[TARGET]] ZII2_Engine
  #[[LINK]]
    ZII2_Math
)
target_link_libraries(
  ZII2_Math
    glm
)
target_link_libraries(Practice ZII2_Engine)

option(ZII2_BUILD_TESTS
  "Do you want to build unit tests?"
  OFF
)

if(ZII2_BUILD_TESTS)
  add_executable(
    ZII2_Tests
    ZII2/Test/gtest_runner.cpp
    ZII2/Test/ZII2_Tests_Main.cpp
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
  PUBLIC
    ${ZII2_INCLUDE_DIR}
  PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    # ${BGFX_INCLUDE_DIR}
    # ${BIMG_INCLUDE_DIR}
    # ${BX_INCLUDE_DIRS}
)

target_include_directories(
  ZII2_Math
  PUBLIC
    ${ZII2_INCLUDE_DIR}
)

target_link_libraries(
  ZII2_Engine
    OpenGL::GL
    ${GLEW_LIBRARY_RELEASE}
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

source_group(
  TREE ${CMAKE_SOURCE_DIR}/ZII2
  FILES ${ZII_ENGINE_SOURCE}
)

source_group(
  TREE ${CMAKE_SOURCE_DIR}/ZII2
  FILES ${ZII_MATH_SOURCE}
)
