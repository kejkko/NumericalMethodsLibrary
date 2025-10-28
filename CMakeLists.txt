cmake_minimum_required(VERSION 3.10)
project(biblioteczka)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_library(biblioteczka ${SOURCES})

# Przykładowe programy
add_executable(example1 examples/example1.cpp)
target_link_libraries(example1 biblioteczka)

add_executable(example2 examples/example2.cpp)
target_link_libraries(example2 biblioteczka)

add_executable(all_methods_test examples/all_methods_test.cpp)
target_link_libraries(all_methods_test biblioteczka)

# Dodanie GoogleTest
add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

enable_testing()

# Testy
file(GLOB TEST_SOURCES "tests/*.cpp")
foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} biblioteczka gtest gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
