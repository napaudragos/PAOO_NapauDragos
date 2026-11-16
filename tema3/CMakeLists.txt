cmake_minimum_required(VERSION 3.10)

project(tema3)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/student.cpp
    src/main.cpp
)
