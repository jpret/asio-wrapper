
# We can add ASIO in the same way we added GTest through CMake's add_ExternalProject()

# START OF COPIED CODE #

# Download and unpack ASIO at configure time
configure_file(CMakeLists.txt.in asio-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/asio-download )
if(result)
  message(FATAL_ERROR "CMake step for ASIO failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/asio-download )
if(result)
  message(FATAL_ERROR "Build step for ASIO failed: ${result}")
endif() 