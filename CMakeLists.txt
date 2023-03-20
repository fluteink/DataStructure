cmake_minimum_required(VERSION 3.24)
project(vscode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(408)

add_executable(vscode
        408/dLinkList.cpp
        408/DynamicLinarList.cpp
        408/linarlist.cpp
        408/SinglyLinkList.cpp
        408/SinglyLinkListWithNoHead.cpp 1/Main.cpp)
