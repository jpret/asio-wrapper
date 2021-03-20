cmake_minimum_required(VERSION 2.8.12)

# Add server example
add_executable(${PROJECT_NAME}_example_server server.cpp)
target_link_libraries(${PROJECT_NAME}_example_server asio_wrapper)

# Add client example
add_executable(${PROJECT_NAME}_example_client client.cpp)
target_link_libraries(${PROJECT_NAME}_example_client asio_wrapper)
