cmake_minimum_required(VERSION 3.10)
project(main C)

set(CMAKE_C_STANDARD 99)

include_directories(../lib/include)

add_executable(main main.c)

target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/lib.a)
