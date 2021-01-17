
# Cpp::Engineer.com 
# Project: asio-wrapper
# Year: 2021

# Welcome to the Top-Level CMakeLists.txt file for the asio-wrapper library #

# We used the Tutorial from cmake.org to setup our initial CMake file #
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html #

# First we'll specify the minimum cmake version for this project
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(asio-wrapper)

# set the project version information
set(asio-wrapper_VERSION_MAJOR 1)
set(asio-wrapper_VERSION_MINOR 0)
set(asio-wrapper_VERSION_PATCH 0)

# specify the c++ standard version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add sub_directories
add_subdirectory(test)
