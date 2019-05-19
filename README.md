# practice-cpp
Practice for C++ code

The Unit Tests for each of the Modules have geen written using the **GTest** test Framework.

### Steps to install GTest for Ubuntu:

1. sudo apt-get install libgtest-dev
2. sudo apt-get install cmake
3. cd /usr/src/gtest
4. sudo cmake CMakeLists.txt
5. sudo make
6. sudo cp \*.a /usr/lib

For more information visit [GTest](https://github.com/google/googletest)

### Steps to build all the SubDirectories at once

1. cd build/
2. cmake ..
3. make

The executables for each subdirectory will be present in the build folder in their respective folders


### Steps to clean and build all the SubDirectories at once

1. ./CleanAndBuild.sh

The executables for each subdirectory will be present in the build folder in their respective folders