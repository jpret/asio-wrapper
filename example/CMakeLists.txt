
# We can automatically clone the asio-wrapper with CMake

# Download and unpack the asio-wrapper at configure time
configure_file(CMakeLists.txt.in asio-wrapper-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/asio-wrapper-download )
if(result)
  message(FATAL_ERROR "CMake step for asio-wrapper failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/asio-wrapper-download )
if(result)
  message(FATAL_ERROR "Build step for asio-wrapper failed: ${result}")
endif()

# Add asio-wrapper directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/asio-wrapper-src
                 ${CMAKE_CURRENT_BINARY_DIR}/asio-wrapper-build)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/asio-wrapper-src/include)

# Link against asio-wrapper to our executable
add_executable(asio-wrapper-example main.cc)
target_link_libraries(asio-wrapper-example asio_wrapper)