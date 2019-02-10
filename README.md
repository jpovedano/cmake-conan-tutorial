# Programming C/C++ like a pro with `CMake`, `conan.io` and `Jenkins`

## Introduction

This repository contains a tutorial that demonstrates a modern workflow to
develop C/C++ applications using best practices and modern techniques.

The idea is not to provide a comprehensive guide on `CMake` or `Jenkins`, but
to help you to understand how they can work together.

## Tutorial

This repository contains the code of a simple library, called `asl`.

### Your C++ source code (tag: `add-source-files`)

In this tag you can see the source files of the `asl` library under the `src`
directory. There are no other files in the
repository so you won't be able to build them using `make` or `Visual Studio`.

### Adding the CMakeList.txt file (tag: `add-cmakelist`)

### Add a test (tag: `add-test`)

Your library is already compiling without warnings, but every time you do a
change you need to test manually by compiling your application by hand. As
you can imagine, this is really test consuming and error-prone.

In this section, we will learn how we can create a new executable using the
`add_executable` command, that can be used to test your library.

### Integrate with CTest (tag: `ctest-integration`)

Now we have an executable that can be used to run tests against our library.
In this section, we will learn how to use `CTest` and `add_test` to run all the 
tests available in our library.


### Using third party dependencies

Programming in C++ can be fun, but sometimes it is not worthy to reinvent
the wheel every time we develop something. There are tons of open source libraries
that are well tested that can help you to develop better programs.

#### OpenSSL (tag: `add-openssl`)

In this section we will cover how can use the `FindPackage` module
to locate third party libraries in `CMake`.

#### GTest and conan.io (tag `add-gtest-conan`)

In this section, we will add a more advanced system to run unit tests: Google
GTest. This suite allows us to run tests and generate advanced reports. We
will show you here how to integrate it with `CTest`.

### Installing your application (tag: `install-rules`)

Here we will learn how we can use the `install` command in `CMake` to
define an installation layout.

### Bundling your application (tag: `create-bundles`)

### Add Continous Integration (tag: `add-ci`)

