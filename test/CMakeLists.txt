cmake_minimum_required(VERSION 2.8.12)

# Build GTest only when we are testing
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

# Keep our Cache clean
# Source: https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html
mark_as_advanced(
        BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
        gmock_build_tests gtest_build_samples gtest_build_tests
        gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
# Keep IDE folders clean
set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

# Add test sources here
set(ASIO_WRAPPER_TEST_SOURCES asio_wrapper_test.cpp)

# Create our test executable and link the gtest_main to it
add_executable(${PROJECT_NAME}_tests ${ASIO_WRAPPER_TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests gtest gtest_main ${PROJECT_NAME})