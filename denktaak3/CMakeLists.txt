cmake_minimum_required(VERSION 3.9)
project(denktaak3 C)

set(CMAKE_C_STANDARD 99)


add_executable(denktaak3 gvar.c gvar.h svar.c)
include_directories(gvar.h)

target_link_libraries(denktaak3 m)