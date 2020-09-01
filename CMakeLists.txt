cmake_minimum_required(VERSION 3.17)
project(FileCoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileCoder main.cpp Parser/IParser.h DataTypes/CommandData.h)