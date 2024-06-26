# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(FinanceApp CXX)

# Set C++ standard (optional)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target
add_executable(FinanceApp
    src/main.cpp
)

# Optionally, add include directories if needed
#target_include_directories

# Optionally, link libraries if needed (e.g., for external dependencies)
# target_link_libraries

# Optionally, specify compiler flags or other build options
# target_compile_options(FinanceApp PRIVATE -Wall)

# Optionally, set build type (Debug or Release)
# set(CMAKE_BUILD_TYPE Release)
