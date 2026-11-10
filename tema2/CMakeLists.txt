cmake_minimum_required(VERSION 3.10)

project(effective_cpp)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -Wall shows the -Wreorder warning (Item 4)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall)
endif()

# -DDEMO_ERORI=ON enables code that must NOT compile (Items 5 and 6)
option(DEMO_ERORI "Activeaza codul interzis (compilarea esueaza intentionat)" OFF)
if(DEMO_ERORI)
    add_definitions(-DDEMO_ERORI)
endif()

add_executable(${PROJECT_NAME}
    inc/martor.hpp
    inc/config.hpp
    inc/item4.hpp
    inc/item5.hpp
    inc/item6.hpp
    src/martor.cpp
    src/config.cpp
    src/item4.cpp
    src/item6.cpp
    src/main.cpp
)
