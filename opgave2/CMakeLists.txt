cmake_minimum_required(VERSION 3.9)
project(opgave2 C)

set(CMAKE_C_STANDARD 99)

add_executable(opgave2 hotel.c txtdat.c lijst.c index.c zoek.c binzoek.c)
include_directories(hotel.h)