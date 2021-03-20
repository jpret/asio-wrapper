
#[[
    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           CMakeLists.txt
    URL: 	        https://github.com/cppengineer/asio-wrapper
]]#
cmake_minimum_required(VERSION 2.8.12)
project(asio_wrapper)

# set the project version information
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

# specify the c++ standard version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add sub_directories
add_subdirectory(src)

# add our tests only if we are building this project
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()
