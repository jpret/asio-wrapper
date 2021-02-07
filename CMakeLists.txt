
# Cpp::Engineer.com 
# Project: asio-wrapper
# Year: 2021

# Welcome to the Top-Level CMakeLists.txt file for the asio-wrapper library #

# We used the Tutorial from cmake.org to setup our initial CMake file #
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html #

# First we'll specify the minimum cmake version for this project
cmake_minimum_required(VERSION 2.8.12)

# Set the project name
project(asio-wrapper)

# set the project version information
set(CMAKE_PROJECT_VERSION_MAJOR 1)
set(CMAKE_PROJECT_VERSION_MINOR 0)
set(CMAKE_PROJECT_VERSION_PATCH 0)

# specify the c++ standard version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO: Add compiler flags

# include directories
include_directories(include
                    ${CMAKE_BINARY_DIR}/lib/asio/asio-src/asio/include)

# add sub_directories
add_subdirectory(lib)

# set the source files
set(ASIO_WRAPPER_SOURCES
    # tcp
    ${PROJECT_SOURCE_DIR}/src/tcp/server.cc 
    ${PROJECT_SOURCE_DIR}/src/tcp/client.cc 
    ${PROJECT_SOURCE_DIR}/src/tcp/acceptor.cc 
    ${PROJECT_SOURCE_DIR}/src/tcp/connector.cc
    ${PROJECT_SOURCE_DIR}/src/tcp/connection_manager.cc 
    ${PROJECT_SOURCE_DIR}/src/tcp/connection.cc)

set(ASIO_WRAPPER_TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/src/tcp/test/tcp_test.cc)

# create and export the library
add_library(asio_wrapper 
            ${ASIO_WRAPPER_SOURCES})
export(PACKAGE asio_wrapper)

# Add test subdirectory
add_subdirectory(test)
