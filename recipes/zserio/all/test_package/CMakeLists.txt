cmake_minimum_required(VERSION 3.15)

project(test_package LANGUAGES CXX)

find_package(zserio REQUIRED CONFIG)

add_library(simple_zs simple.zs)
zserio_generate_cpp(
    TARGET simple_zs
    GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp
    EXTRA_ARGS
        -setTopLevelPackage top.level
        -withTypeInfoCode
        -withReflectionCode
        -setCppAllocator polymorphic
        -withoutSourcesAmalgamation
)
target_link_libraries(simple_zs PUBLIC zserio::ZserioCppRuntime)
target_include_directories(simple_zs PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/cpp)

add_executable(${PROJECT_NAME} test_package.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE simple_zs)
