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
    src/Transaction.cpp
    src/TransactionManager.cpp
    src/TransactionFileIO.cpp
    src/Utility.cpp
    src/TransactionFileIO.h
    src/Transaction.h      
    src/TransactionManager.h
    src/Utility.h
)

# Optionally, set build type (Debug or Release)
# set(CMAKE_BUILD_TYPE Release)
