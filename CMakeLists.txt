cmake_minimum_required(VERSION 3.10)

project(catalog)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(SHALLOW_COPY "Foloseste copy constructor-ul implicit (gresit)" OFF)
if(SHALLOW_COPY)
    add_definitions(-DSHALLOW_COPY)
endif()

add_executable(${PROJECT_NAME}
    inc/student/student.hpp
    src/student.cpp
    src/main.cpp
)
