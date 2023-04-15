cmake_minimum_required(VERSION 3.5)

project(reburn LANGUAGES CXX)

option(REBURN_UNICODE "Enable Unicode on Windows" ON)

# Statically link UCRT, improves ability to run on XP when compiled with v141_xp
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

add_executable(reburn3 WIN32
  # Must be kept at the top to ensure correct memory mapping
  #src/memory.cpp

  src/main.cpp
  #src/memory.h
  src/res/res.rc
  src/wndproc.cpp
  src/wndproc.h

  src/cxbx/cxbxbinding.cpp
  src/cxbx/cxbxbinding.h
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
  src/dllmain.cpp
  src/inject.cpp
  src/inject.h
)

if (REBURN_UNICODE)
  target_compile_definitions(reburn3 PRIVATE UNICODE _UNICODE)
  target_compile_definitions(reburn3inject PRIVATE UNICODE _UNICODE)
endif()