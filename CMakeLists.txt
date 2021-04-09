cmake_minimum_required(VERSION 3.19)
project(agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda src/main.c src/menu.c src/modelo.h src/arquivo.c src/menu_telefone.c src/arquivo.h
        src/menu_telefone.h src/menu.h src/menu_email.c src/menu_email.h src/menu_pessoa.c src/menu_pessoa.h
)