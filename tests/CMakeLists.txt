# Test executable
add_executable(all_tests
    test_queue.cpp
    test_square.cpp
    test_singleton.cpp
    test_hex2ascii.cpp
    test_rational.cpp
    test_stack.cpp
    test_factorial.cpp
    test_point.cpp
    test_array_utils.cpp
    test_xor_swap.cpp
    test_module2.cpp
    test_queue_array.cpp
    test_stack_queue_linked.cpp
    test_template_sum.cpp
)

# Link against gtest and gtest_main
target_link_libraries(all_tests
    gtest
    gtest_main
    pthread
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(all_tests)
