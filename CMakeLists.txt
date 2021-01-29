cmake_minimum_required(VERSION 3.19)
project(telumo C)

set(CMAKE_C_STANDARD 99)

add_library(telumo SHARED telumo.c telumo.h linked_list.c linked_list.h utils.c utils.h)