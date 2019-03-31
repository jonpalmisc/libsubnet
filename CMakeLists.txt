cmake_minimum_required(VERSION 3.13)
project(libsubnet C)

set(CMAKE_C_STANDARD 99)

add_library(subnet SHARED src/libsubnet/subnet.c src/libsubnet/network.c)
target_include_directories(subnet PUBLIC include)

add_executable(demo examples/demo.c include/libsubnet/network.h)
target_include_directories(demo PUBLIC include)
target_link_libraries(demo subnet)