cmake_minimum_required(VERSION 3.5)

project(reburn LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

add_executable(reburn3 WIN32
  # Must be kept at the top to ensure correct memory mapping
  src/memory.cpp

  src/inject.cpp
  src/inject.h
  src/main.cpp
  src/memory.h
  src/wndproc.cpp
  src/wndproc.h

  src/cxbx/cxbxbinding.cpp
  src/cxbx/cxbxbinding.h
)

target_link_options(reburn3 PRIVATE
  /INCREMENTAL:NO
  /BASE:0x10000
  /FIXED
  /DYNAMICBASE:NO
  /SAFESEH:NO
)

target_link_libraries(reburn3 PRIVATE
)
