cmake_minimum_required(VERSION 3.9)
project(Programeertechniekeni)

set(CMAKE_CXX_STANDARD 11)

add_executable(geheugenbeheer
        geheugenbeheer/a.c
        geheugenbeheer/d.c
        geheugenbeheer/had.c
        geheugenbeheer/had.h)
