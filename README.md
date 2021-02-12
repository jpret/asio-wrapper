# asio-wrapper #
This repository provides an **ASIO** socket communication wrapper written in C++11. The aim is to wrap the infamous [ASIO](https://think-async.com/Asio/)
library with an easy-to-use interface for tcp **client** / **server** implementations.

## Anouncements ##
***This wrapper is currently still in development and testing***

## Features ##
+ TCP Socket Server implementation using ASIO
+ TCP Socket Client implementation using ASIO

## Supported Platforms ##

### Operating Systems ###
+ Linux
+ Windows

### Compilers ###
+ GCC 4.8+
+ MSVC 2015+

### Build Systems ###
+ CMake minimum 2.8.12

### ASIO ###
+ asio-1-18-1

## Getting started ##

+ You can add [ASIO](https://think-async.com/Asio/) to your project in the same way as shown in the **lib** folder, or *download* it and add asio to your **include** path.
+ Add the **asio-wrapper.hpp** header to your include path and the **asio-wrapper.cpp** source to your build.

### Example ###
//TODO: Add example usage here