cmake_minimum_required(VERSION 3.15)

project(hadrian LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(hadrian STATIC
    src/algorithms/carrays_static.c
    src/iterator/iterator.c
)

target_include_directories(hadrian PUBLIC src)

add_executable(carrays_static_test
    tests/carrays_static_test.c
)

target_link_libraries(carrays_static_test PRIVATE hadrian)

add_executable(iterator_test1
    tests/iterator_test1.c
)

target_link_libraries(iterator_test1 PRIVATE hadrian)
