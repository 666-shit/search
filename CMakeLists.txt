cmake_minimum_required(VERSION 3.23)
project(search)

set(CMAKE_CXX_STANDARD 14)

add_executable(search main.cpp)
add_executable(search-1 顺序查找.cpp)
add_executable(search-2 折半查找.cpp)
add_executable(search-3 二叉排序树.cpp)
add_executable(search-4 平衡二叉树.cpp)
add_executable(search-5 B树.cpp)
add_executable(search-6 B+树.cpp)
add_executable(search-7 散列表.cpp)
