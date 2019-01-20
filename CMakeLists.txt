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

################################################################################
# Build Sample Executable
################################################################################
add_executable(
  Sample
  main.cpp
)
target_include_directories(Sample PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(Sample ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
