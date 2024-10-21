# Add the test executable
add_executable(reserve_test reserve_test.cpp)
target_link_libraries(reserve_test gtest_main)
add_test(NAME reserve_test COMMAND reserve_test)