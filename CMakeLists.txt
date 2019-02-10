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
set_target_properties(asl
    PROPERTIES
        PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/src/asl.hpp
)
target_link_libraries(asl PUBLIC CONAN_PKG::OpenSSL)

# Tests
enable_testing()
add_executable(asltest ${CMAKE_SOURCE_DIR}/src/test/asltest.cxx)
target_link_libraries(asltest asl CONAN_PKG::gtest)
add_test(NAME asltest COMMAND asltest --gtest_output=xml:results.xml)

# Installation (relative to CMAKE_INSTALL_PREFIX)
install(TARGETS asl
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

# Bundling
set(CPACK_PACKAGE_CONTACT "Javier Povedano")
set(CPACK_GENERATOR "STGZ;TGZ;TZ;DEB")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CMake + Conan Tutorial")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
include(CPack)
