cmake_policy(SET CMP0048 NEW)

# Set cmake project information.
project(mymath VERSION 1.0.0)

# Set minimum cmake requirements.
cmake_minimum_required(VERSION 3.18)

# Change the default compiler to GCC.
set(CMAKE_C_COMPILER "gcc")

# Change the default compiler to G++.
set(CMAKE_CXX_COMPILER "g++")

# Do not allow cmake to specify a C standard. Manually specify a C standard.
set(CMAKE_C_STANDARD_REQUIRED OFF)

# Set C flags for various cmake build environments.
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -std=c99 -ftree-vectorize -msse2 -mfpmath=sse")  # add -pedantic later
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb3 -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Set a custom binary output directory path.
set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Set the include directory.
include_directories("${PROJECT_SOURCE_DIR}/include")

# The the library binary directory.
link_directories("${PROJECT_SOURCE_DIR}/libexec")

# Build all project subdirectorties.
add_subdirectory("${PROJECT_SOURCE_DIR}/src")
add_subdirectory("${PROJECT_SOURCE_DIR}/test")
add_subdirectory("${PROJECT_SOURCE_DIR}/test/benchmark")

# Import the CMake testing framework.
include(CTest)

# Configure software tests.
add_test(NAME cbrt_test  COMMAND cbrt_test)
add_test(NAME cub_test   COMMAND cub_test)
add_test(NAME exp_test   COMMAND exp_test)
add_test(NAME fabs_test  COMMAND fabs_test)
add_test(NAME floor_test COMMAND floor_test)

# Configure software tests.
add_test(NAME cbrt_bm_test  COMMAND cbrt_bm_test)
add_test(NAME cub_bm_test   COMMAND cub_bm_test)
add_test(NAME exp_bm_test   COMMAND exp_bm_test)
add_test(NAME fabs_bm_test  COMMAND fabs_bm_test)
add_test(NAME floor_bm_test COMMAND floor_bm_test)
