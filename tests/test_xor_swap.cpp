#include <gtest/gtest.h>

// XOR swap function from 03/10_xor_swap/main.cpp
void xor_swap(int& a, int& b) {
    a ^= b ^= a ^= b;
}

// Alternative XOR swap implementation for testing
void xor_swap_verbose(int& a, int& b) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

// Tests
class XorSwapTest : public ::testing::Test {};

// Test 1: Basic swap
TEST_F(XorSwapTest, BasicSwap) {
    int a = 2, b = 325;
    xor_swap(a, b);
    EXPECT_EQ(a, 325);
    EXPECT_EQ(b, 2);
}

// Test 2: Verbose swap
TEST_F(XorSwapTest, VerboseSwap) {
    int a = 2, b = 325;
    xor_swap_verbose(a, b);
    EXPECT_EQ(a, 325);
    EXPECT_EQ(b, 2);
}

// Test 3: Both methods equivalent
TEST_F(XorSwapTest, BothMethodsEquivalent) {
    int a1 = 23325, b1 = -2135;
    int a2 = a1, b2 = b1;

    xor_swap(a1, b1);
    xor_swap_verbose(a2, b2);

    EXPECT_EQ(a1, a2);
    EXPECT_EQ(b1, b2);
}

// Test 4: Positive numbers
TEST_F(XorSwapTest, PositiveNumbers) {
    int a = 100, b = 200;
    xor_swap(a, b);
    EXPECT_EQ(a, 200);
    EXPECT_EQ(b, 100);
}

// Test 5: Negative numbers
TEST_F(XorSwapTest, NegativeNumbers) {
    int a = -50, b = -100;
    xor_swap(a, b);
    EXPECT_EQ(a, -100);
    EXPECT_EQ(b, -50);
}

// Test 6: Mixed positive and negative
TEST_F(XorSwapTest, MixedSigns) {
    int a = 42, b = -42;
    xor_swap(a, b);
    EXPECT_EQ(a, -42);
    EXPECT_EQ(b, 42);
}

// Test 7: Zero and positive
TEST_F(XorSwapTest, ZeroAndPositive) {
    int a = 0, b = 99;
    xor_swap(a, b);
    EXPECT_EQ(a, 99);
    EXPECT_EQ(b, 0);
}

// Test 8: Zero and negative
TEST_F(XorSwapTest, ZeroAndNegative) {
    int a = 0, b = -99;
    xor_swap(a, b);
    EXPECT_EQ(a, -99);
    EXPECT_EQ(b, 0);
}

// Test 9: Both zeros
TEST_F(XorSwapTest, BothZeros) {
    int a = 0, b = 0;
    xor_swap(a, b);
    EXPECT_EQ(a, 0);
    EXPECT_EQ(b, 0);
}

// Test 10: Large values
TEST_F(XorSwapTest, LargeValues) {
    int a = 1000000, b = 2000000;
    xor_swap(a, b);
    EXPECT_EQ(a, 2000000);
    EXPECT_EQ(b, 1000000);
}

// Test 11: Powers of 2
TEST_F(XorSwapTest, PowersOfTwo) {
    int a = 256, b = 512;
    xor_swap(a, b);
    EXPECT_EQ(a, 512);
    EXPECT_EQ(b, 256);
}

// Test 12: Same values (edge case)
TEST_F(XorSwapTest, SameValues) {
    int a = 42, b = 42;
    int original_a = a, original_b = b;
    xor_swap(a, b);
    // When swapping same values, they should remain unchanged
    EXPECT_EQ(a, original_b);
    EXPECT_EQ(b, original_a);
}

// Test 13: One and zero
TEST_F(XorSwapTest, OneAndZero) {
    int a = 1, b = 0;
    xor_swap(a, b);
    EXPECT_EQ(a, 0);
    EXPECT_EQ(b, 1);
}

// Test 14: Sequential swap
TEST_F(XorSwapTest, SequentialSwap) {
    int a = 10, b = 20;
    xor_swap(a, b); // a=20, b=10
    EXPECT_EQ(a, 20);
    EXPECT_EQ(b, 10);
    xor_swap(a, b); // a=10, b=20
    EXPECT_EQ(a, 10);
    EXPECT_EQ(b, 20);
}

// Test 15: Very large negative
TEST_F(XorSwapTest, VeryLargeNegative) {
    int a = -1000000, b = -2000000;
    xor_swap(a, b);
    EXPECT_EQ(a, -2000000);
    EXPECT_EQ(b, -1000000);
}
