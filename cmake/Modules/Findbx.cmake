include(FindPackageHandleStandardArgs)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(BX_ARCH_SUFFIX x64)
else()
  set(BX_ARCH_SUFFIX x86)
endif()

set(BX_SEARCH_PATHS
# ${CMAKE_PREFIX_PATH} := D:\Modus Ponens\Libraries
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  ${BX_PATH}
)

set(BX_INCLUDE_SUFFIXES
  include
  include/bx
  bx
  bx/include
)

set(BX_LIBRARY_SUFFIXES
  lib/${BX_ARCH_SUFFIX}
  lib/bx/${BX_ARCH_SUFFIX}
  bx/lib/${BX_ARCH_SUFFIX}
  lib
)

find_path(
  BX_INCLUDE_DIR
  NAMES
    bx/bx.h
  HINTS
    $ENV{BXDIR}
  PATHS
    ${BX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BX_INCLUDE_SUFFIXES}
)

find_library(
  BX_LIBRARY_RELEASE
  NAMES
    bxRelease
  HINTS
    $ENV{BXDIR}
  PATHS
    ${BX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BX_LIBRARY_SUFFIXES}
)

find_library(
  BX_LIBRARY_DEBUG
  NAMES
    bxDebug
  HINTS
    $ENV{BXDIR}
  PATHS
    ${BX_SEARCH_PATHS}
  PATH_SUFFIXES
    ${BX_LIBRARY_SUFFIXES}
)

if(WIN32)
  set(BX_COMPAT_DIR "${BX_INCLUDE_DIR}/compat/msvc" CACHE PATH "Path to the platform compat headers.")
else()
  message(WARNING "Findbx.cmake does not support this platform - please update!")
endif()

set(BX_INCLUDE_DIRS "${BX_COMPAT_DIR}" "${BX_INCLUDE_DIR}")

find_package_handle_standard_args(
  BX
  REQUIRED_VARS
    BX_LIBRARY_RELEASE
    BX_LIBRARY_DEBUG
    BX_INCLUDE_DIR
    BX_COMPAT_DIR
)
