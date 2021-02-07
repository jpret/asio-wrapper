# asio-wrapper #
This repository provides an ASIO socket communication wrapper written in C++11. The aim is to wrap the infamous [ASIO](https://think-async.com/Asio/)
library with an easy-to-use interface for client / server implementations.

## Features ##
+ TCP Socket Server using ASIO
+ TCP Socket Client using ASIO

## Supported Platforms ##
### Operating Systems ###
+ Linux
+ Windows
### Compilers ###
+ GCC 4.8+
+ MSVC 2015+
### Build Systems ###
+ CMake minimum 2.8.12

## Getting started ##
+ Clone this repository 
+ include the asio-wrapper root folder as a `sub_directory()` of your CMakeLists.txt file.
+ Add the *include* folder to your `include_directories()`


# License
MIT

# Support