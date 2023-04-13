cmake_minimum_required(VERSION 3.5)

project(reburn LANGUAGES CXX)

add_executable(reburn3 WIN32
  # Must be kept at the top to ensure correct memory mapping
  src/memory.cpp

  src/main.cpp
  src/memory.h
)

target_link_options(reburn3 PRIVATE
  /INCREMENTAL:NO
  /BASE:0x10000
  /FIXED
  /DYNAMICBASE:NO
  /SAFESEH:NO
  /NODEFAULTLIB
)

target_link_libraries(reburn3 PRIVATE
)
