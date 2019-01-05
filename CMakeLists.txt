cmake_minimum_required(VERSION 3.10)
project(asl VERSION 1.0)

# Find the requirements
find_package(OpenSSL REQUIRED)

# Library
add_library(asl ${CMAKE_SOURCE_DIR}/src/asl.cxx)
target_include_directories(asl PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(asl PUBLIC OpenSSL::Crypto)

# Tests
enable_testing()
add_executable(asltest ${CMAKE_SOURCE_DIR}/src/test/asltest.cxx)
target_link_libraries(asltest asl)
add_test(asltest ${CMAKE_BINARY_DIR}/asltest)