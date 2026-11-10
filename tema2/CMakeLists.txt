cmake_minimum_required(VERSION 3.10)

project(effective_cpp)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -Wall: ca sa vedem warning-ul despre ordinea de initializare (Item 4)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall)
endif()

# Cu -DDEMO_ERORI=ON se activeaza liniile care NU trebuie sa compileze
# (Item 5 si Item 6). Compilarea va esua intentionat, ca sa vedem erorile.
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
