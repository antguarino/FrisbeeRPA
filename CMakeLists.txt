cmake_minimum_required(VERSION 3.15)
project(FrisbeeRPA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(matplotplusplus)
add_subdirectory(opencv)

add_executable(run_frisbee.exe 
    src/app_frisbee.cpp
    src/FrisbeeRPA.cpp
    src/GraphGenerator.cpp
    src/VideoProcessing.cpp

    src/FrisbeeRPA.h
)
