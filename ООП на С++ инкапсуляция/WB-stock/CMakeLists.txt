cmake_minimum_required(VERSION 3.28)
project(WB_stock)

set(CMAKE_CXX_STANDARD 17)

add_executable(WB_stock main.cpp
        Stock.h
        Stock.cpp)
