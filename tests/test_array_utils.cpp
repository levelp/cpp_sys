#include <gtest/gtest.h>

// Array utility functions from 03/06_array_task/sol.cpp
int sum(int A[], int N) {
    int result = 0;
    for(int i = 0; i < N; ++i)
        if(i % 2 == 0)
            result += A[i];
        else
            result -= A[i];
    return result;
}

int sum2(int A[], int N) {
    int result = 0;
    for(int i = 0; i < N; i += 2)
        result += A[i];
    for(int i = 1; i < N; i += 2)
        result -= A[i];
    return result;
}

// Tests
class ArrayUtilsTest : public ::testing::Test {};

// Test 1: Sum with example from file
TEST_F(ArrayUtilsTest, SumExample) {
    int A[] = {1, 3, -2, 4, 2, 10};
    EXPECT_EQ(sum(A, 6), -16);
}

// Test 2: Sum2 with same example
TEST_F(ArrayUtilsTest, Sum2Example) {
    int A[] = {1, 3, -2, 4, 2, 10};
    EXPECT_EQ(sum2(A, 6), -16);
}

// Test 3: Sum and Sum2 are equivalent
TEST_F(ArrayUtilsTest, SumAndSum2Equivalent) {
    int A[] = {1, 3, -2, 4, 2, 10};
    EXPECT_EQ(sum(A, 6), sum2(A, 6));
}

// Test 4: Single element
TEST_F(ArrayUtilsTest, SingleElement) {
    int A[] = {42};
    EXPECT_EQ(sum(A, 1), 42);
    EXPECT_EQ(sum2(A, 1), 42);
}

// Test 5: Two elements
TEST_F(ArrayUtilsTest, TwoElements) {
    int A[] = {10, 5};
    // 10 - 5 = 5
    EXPECT_EQ(sum(A, 2), 5);
    EXPECT_EQ(sum2(A, 2), 5);
}

// Test 6: All positive
TEST_F(ArrayUtilsTest, AllPositive) {
    int A[] = {1, 2, 3, 4, 5, 6};
    // 1 - 2 + 3 - 4 + 5 - 6 = -3
    EXPECT_EQ(sum(A, 6), -3);
    EXPECT_EQ(sum2(A, 6), -3);
}

// Test 7: All negative
TEST_F(ArrayUtilsTest, AllNegative) {
    int A[] = {-1, -2, -3, -4};
    // -1 - (-2) + (-3) - (-4) = -1 + 2 - 3 + 4 = 2
    EXPECT_EQ(sum(A, 4), 2);
    EXPECT_EQ(sum2(A, 4), 2);
}

// Test 8: All zeros
TEST_F(ArrayUtilsTest, AllZeros) {
    int A[] = {0, 0, 0, 0};
    EXPECT_EQ(sum(A, 4), 0);
    EXPECT_EQ(sum2(A, 4), 0);
}

// Test 9: Empty array (edge case)
TEST_F(ArrayUtilsTest, EmptyArray) {
    int A[] = {};
    EXPECT_EQ(sum(A, 0), 0);
    EXPECT_EQ(sum2(A, 0), 0);
}

// Test 10: Alternating signs
TEST_F(ArrayUtilsTest, AlternatingSigns) {
    int A[] = {5, -5, 10, -10};
    // 5 - (-5) + 10 - (-10) = 5 + 5 + 10 + 10 = 30
    EXPECT_EQ(sum(A, 4), 30);
    EXPECT_EQ(sum2(A, 4), 30);
}

// Test 11: Large positive values
TEST_F(ArrayUtilsTest, LargeValues) {
    int A[] = {1000, 500, 2000, 1500};
    // 1000 - 500 + 2000 - 1500 = 1000
    EXPECT_EQ(sum(A, 4), 1000);
    EXPECT_EQ(sum2(A, 4), 1000);
}

// Test 12: Odd length array
TEST_F(ArrayUtilsTest, OddLength) {
    int A[] = {1, 2, 3, 4, 5};
    // 1 - 2 + 3 - 4 + 5 = 3
    EXPECT_EQ(sum(A, 5), 3);
    EXPECT_EQ(sum2(A, 5), 3);
}

// Test 13: Even length array
TEST_F(ArrayUtilsTest, EvenLength) {
    int A[] = {1, 2, 3, 4, 5, 6};
    // 1 - 2 + 3 - 4 + 5 - 6 = -3
    EXPECT_EQ(sum(A, 6), -3);
    EXPECT_EQ(sum2(A, 6), -3);
}

// Test 14: Mixed small values
TEST_F(ArrayUtilsTest, MixedSmallValues) {
    int A[] = {1, 1, 1, 1};
    // 1 - 1 + 1 - 1 = 0
    EXPECT_EQ(sum(A, 4), 0);
    EXPECT_EQ(sum2(A, 4), 0);
}

// Test 15: Negative at even positions
TEST_F(ArrayUtilsTest, NegativeAtEvenPositions) {
    int A[] = {-5, 10, -15, 20};
    // -5 - 10 + (-15) - 20 = -50
    EXPECT_EQ(sum(A, 4), -50);
    EXPECT_EQ(sum2(A, 4), -50);
}
