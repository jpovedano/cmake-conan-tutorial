cmake_minimum_required(VERSION 3.10)
project(asl VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Find the requirements
find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)

# Library
add_library(asl ${CMAKE_SOURCE_DIR}/src/asl.cxx)
target_include_directories(asl PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(asl PUBLIC CONAN_PKG::OpenSSL)

# Tests
enable_testing()
add_executable(asltest ${CMAKE_SOURCE_DIR}/src/test/asltest.cxx)
target_link_libraries(asltest asl CONAN_PKG::gtest)
add_test(NAME asltest COMMAND asltest)