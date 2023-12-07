cmake_minimum_required(VERSION 3.5)

project(reburn LANGUAGES CXX)

# On MinGW, "lib" will get prepended to libraries which will break out ability
# to inject our DLL.
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_IMPORT_LIBRARY_PREFIX "")

option(REBURN_UNICODE "Enable Unicode on Windows" ON)

# Statically link UCRT, improves ability to run on XP when compiled with v141_xp
#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

add_executable(reburn3 WIN32
  # Must be kept at the top to ensure correct memory mapping
  #src/memory.cpp

  src/define.cpp
  src/main.cpp
  #src/memory.h
  src/res/res.rc
  src/wndproc.cpp
  src/wndproc.h

  src/cxbx/cxbxbinding.cpp
  src/cxbx/cxbxbinding.h
)

target_link_libraries(reburn3 PRIVATE
  shlwapi
)

# We aren't currently loading the XBE on our end, so this is unnecessary
#target_link_options(reburn3 PRIVATE
#  /INCREMENTAL:NO
#  /BASE:0x10000
#  /FIXED
#  /DYNAMICBASE:NO
#  /SAFESEH:NO
#)

add_library(reburn3inject SHARED
  src/define.cpp
  src/dllmain.cpp
  src/inject.cpp
  src/game/cb3graphicsmanager.cpp
)

include_directories(
  /home/matt/src/msvc/vc/tools/msvc/14.38.33130/include
  /home/matt/src/msvc/kits/10/include/10.0.22621.0/shared
  /home/matt/src/msvc/kits/10/include/10.0.22621.0/ucrt
  /home/matt/src/msvc/kits/10/include/10.0.22621.0/um
  /home/matt/src/msvc/kits/10/include/10.0.22621.0/winrt

  ${CMAKE_SOURCE_DIR}/thirdparty/d3d8/include
  ${CMAKE_SOURCE_DIR}/thirdparty/rw/include/d3d8/
)

target_link_directories(reburn3inject PRIVATE
  ${CMAKE_SOURCE_DIR}/thirdparty/d3d8/lib
  ${CMAKE_SOURCE_DIR}/thirdparty/d3d8/lib
  $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/thirdparty/rw/lib/d3d8/debug>
  $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/thirdparty/rw/lib/d3d8/release>
  $<$<CONFIG:RelWithDebInfo>:${CMAKE_SOURCE_DIR}/thirdparty/rw/lib/d3d8/release>
)

target_link_libraries(reburn3inject PRIVATE
  d3d8
  rwcore
  rtfsyst
  legacy_stdio_definitions
)

if (REBURN_UNICODE)
  target_compile_definitions(reburn3 PRIVATE UNICODE _UNICODE)
  target_compile_definitions(reburn3inject PRIVATE UNICODE _UNICODE)
endif()
