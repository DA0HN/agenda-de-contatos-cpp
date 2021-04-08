cmake_minimum_required(VERSION 3.19)
project(agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda src/main.c src/menu.c src/modelo.c src/arquivo.c)