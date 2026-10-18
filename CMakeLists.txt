cmake_minimum_required(VERSION 3.15)
project(hadrian)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(carrays_static_test
    tests/carrays_static_test.c
    src/algorithms/carrays_static.c
)

add_executable(iterator_test1
    tests/iterator_test1.c
    src/iterator/iterator.c
)

target_include_directories(carrays_static_test PRIVATE src)
target_include_directories(iterator_test1 PRIVATE src)
