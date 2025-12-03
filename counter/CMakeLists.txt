cmake_minimum_required(VERSION 3.10)
project(counter C)

set(CMAKE_C_STANDARD 99)

set(SOURCES
    counter.c
)

if(WIN32)
    message(STATUS "Собираем под Windows")

    set(EXTRA_LIBS
        kernel32
    )
else()
    message(STATUS "Собираем под Linux")

    set(EXTRA_LIBS "")
endif()

add_executable(counter ${SOURCES})

target_link_libraries(counter ${EXTRA_LIBS})
