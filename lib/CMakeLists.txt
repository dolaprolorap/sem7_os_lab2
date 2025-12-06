cmake_minimum_required(VERSION 3.10)
project(lib C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

if(WIN32)
    message(STATUS "Собираем под Windows")

    set(SOURCES
        src/win.c
    )

    set(EXTRA_LIBS
        kernel32
    )
else()
    message(STATUS "Собираем под Linux")

    set(SOURCES
        src/posix.c
    )

    set(EXTRA_LIBS "")
endif()

add_library(lib STATIC ${SOURCES})

set_target_properties(lib PROPERTIES
    OUTPUT_NAME "lib"
    PREFIX ""
)

install(TARGETS lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)

target_link_libraries(lib ${EXTRA_LIBS})
