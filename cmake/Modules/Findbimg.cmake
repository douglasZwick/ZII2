include(FindPackageHandleStandardArgs)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(BIMG_ARCH_SUFFIX x64)
else()
  set(BIMG_ARCH_SUFFIX x86)
endif()

set(BIMG_SEARCH_PATHS
# ${CMAKE_PREFIX_PATH} := D:\Modus Ponens\Libraries
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  ${BIMG_PATH}
)

set(BIMG_INCLUDE_SUFFIXES
  include
  include/bimg
  bimg
  bimg/include
)

set(BIMG_LIBRARY_SUFFIXES
  lib/${BIMG_ARCH_SUFFIX}
  lib/bimg/${BIMG_ARCH_SUFFIX}
  bimg/lib/${BIMG_ARCH_SUFFIX}
  lib
)

find_path(
  BIMG_INCLUDE_DIR
  NAMES
    bimg/bimg.h
  HINTS
    $ENV{BIMGDIR}
  PATHS
    ${BIMG_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BIMG_INCLUDE_SUFFIXES}
)

find_library(
  BIMG_LIBRARY_RELEASE
  NAMES
    bimgRelease
  HINTS
    ${BIMG_SEARCH_PATHS}
  PATHS
    ${BIMG_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BIMG_LIBRARY_SUFFIXES}
)

find_library(
  BIMG_LIBRARY_DEBUG
  NAMES
    bimgDebug
  HINTS
    ${BIMG_SEARCH_PATHS}
  PATHS
    ${BIMG_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BIMG_LIBRARY_SUFFIXES}
)

find_package_handle_standard_args(
  BIMG
  REQUIRED_VARS
    BIMG_LIBRARY_RELEASE
    BIMG_LIBRARY_DEBUG
    BIMG_INCLUDE_DIR
)
