cmake_minimum_required(VERSION 3.29)
project(lab_11 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_11 main.c headers/binary_search_tree.h sources/binary_search_tree.c)
