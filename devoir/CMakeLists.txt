cmake_minimum_required(VERSION 3.5)
project(Devoir)

add_executable(exo devoir.c hashcode.h hashcode.c freel-liste.h freel-liste.c)

target_compile_options(exo PRIVATE -Wall -Wextra -Wpedantic -Werror)