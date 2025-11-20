#include <gtest/gtest.h>

// Factorial function from 02/07_factorial_rec/main.cpp
long long factorial(int N) {
    if(N == 0)
        return 1;
    else
        return N * factorial(N - 1);
}

// Tests
class FactorialTest : public ::testing::Test {};

// Test 1: Factorial of 0
TEST_F(FactorialTest, FactorialZero) {
    EXPECT_EQ(factorial(0), 1);
}

// Test 2: Factorial of 1
TEST_F(FactorialTest, FactorialOne) {
    EXPECT_EQ(factorial(1), 1);
}

// Test 3: Factorial of 2
TEST_F(FactorialTest, FactorialTwo) {
    EXPECT_EQ(factorial(2), 2);
}

// Test 4: Factorial of 3
TEST_F(FactorialTest, FactorialThree) {
    EXPECT_EQ(factorial(3), 6);
}

// Test 5: Factorial of 4
TEST_F(FactorialTest, FactorialFour) {
    EXPECT_EQ(factorial(4), 24);
}

// Test 6: Factorial of 5
TEST_F(FactorialTest, FactorialFive) {
    EXPECT_EQ(factorial(5), 120);
}

// Test 7: Factorial of 6
TEST_F(FactorialTest, FactorialSix) {
    EXPECT_EQ(factorial(6), 720);
}

// Test 8: Factorial of 7
TEST_F(FactorialTest, FactorialSeven) {
    EXPECT_EQ(factorial(7), 5040);
}

// Test 9: Factorial of 8
TEST_F(FactorialTest, FactorialEight) {
    EXPECT_EQ(factorial(8), 40320);
}

// Test 10: Factorial of 9
TEST_F(FactorialTest, FactorialNine) {
    EXPECT_EQ(factorial(9), 362880);
}

// Test 11: Factorial of 10
TEST_F(FactorialTest, FactorialTen) {
    EXPECT_EQ(factorial(10), 3628800);
}

// Test 12: Factorial of 11
TEST_F(FactorialTest, FactorialEleven) {
    EXPECT_EQ(factorial(11), 39916800);
}

// Test 13: Factorial of 12
TEST_F(FactorialTest, FactorialTwelve) {
    EXPECT_EQ(factorial(12), 479001600);
}

// Test 14: Factorial of 13
TEST_F(FactorialTest, FactorialThirteen) {
    EXPECT_EQ(factorial(13), 6227020800LL);
}

// Test 15: Factorial of 14
TEST_F(FactorialTest, FactorialFourteen) {
    EXPECT_EQ(factorial(14), 87178291200LL);
}

// Test 16: Factorial of 15
TEST_F(FactorialTest, FactorialFifteen) {
    EXPECT_EQ(factorial(15), 1307674368000LL);
}

// Test 17: Factorial of 16
TEST_F(FactorialTest, FactorialSixteen) {
    EXPECT_EQ(factorial(16), 20922789888000LL);
}

// Test 18: Factorial of 17
TEST_F(FactorialTest, FactorialSeventeen) {
    EXPECT_EQ(factorial(17), 355687428096000LL);
}

// Test 19: Factorial of 18
TEST_F(FactorialTest, FactorialEighteen) {
    EXPECT_EQ(factorial(18), 6402373705728000LL);
}

// Test 20: Factorial of 19
TEST_F(FactorialTest, FactorialNineteen) {
    EXPECT_EQ(factorial(19), 121645100408832000LL);
}

// Test 21: Factorial of 20
TEST_F(FactorialTest, FactorialTwenty) {
    EXPECT_EQ(factorial(20), 2432902008176640000LL);
}
