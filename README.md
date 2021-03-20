# asio-wrapper #
This repository provides an **ASIO** socket communication wrapper written in C++11. The aim is to wrap the infamous [ASIO](https://think-async.com/Asio/)
library with an easy-to-use interface for tcp **client** / **server** implementations.

## Announcements ##
The initial release version is available:
+ v1.0.0

## Features ##
+ TCP Socket Server implementation using ASIO
+ TCP Socket Client implementation using ASIO

### CMake Support ###
+ CMake minimum 2.8.12

### ASIO Version ###
+ asio-1-18-1

## Getting started ##

+ Clone this repo and build the library with (on **Linux**):
```sh
mkdir build
cd build
cmake ..
make
```
+ Or Load the project as a *CMake project* in *MS Visual Studio* for **Windows**
+ Note that the repository uses *git submodules* to include *ASIO* and *GTest*
+ Link the **asio_wrapper** library to your target in CMake;   
+ `#include "asio_wrapper/asio_wrapper.h"` where required; and
+ Implement the `WritableHandler` abstract class for handling your callbacks

### Example ###
See the Example folder for a implementation of a **server** and a **client**