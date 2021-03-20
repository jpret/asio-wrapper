cmake_minimum_required(VERSION 2.8.12)

# set the source files
set(ASIO_WRAPPER_SOURCES asio_wrapper.cpp)

# create the library and link the include directory
add_library(${PROJECT_NAME} ${ASIO_WRAPPER_SOURCES})
if (MINGW)
    target_link_libraries(${PROJECT_NAME} ws2_32 wsock32)
endif ()
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/extern/asio/asio/include)