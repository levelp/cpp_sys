#include <gtest/gtest.h>
#include <cmath>
#include "../04/06_getter_setter_square/square.h"
#include "../04/06_getter_setter_square/square.cpp"

class SquareTest : public ::testing::Test {
protected:
    Square* square;

    void SetUp() override {
        square = new Square();
    }

    void TearDown() override {
        delete square;
    }
};

// Test 1: Set and get side
TEST_F(SquareTest, SetAndGetSide) {
    square->setSide(5.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 5.0);
}

// Test 2: Get area from side
TEST_F(SquareTest, GetAreaFromSide) {
    square->setSide(4.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 16.0);
}

// Test 3: Set area and get side
TEST_F(SquareTest, SetAreaAndGetSide) {
    square->setArea(25.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 5.0);
}

// Test 4: Set area and get area
TEST_F(SquareTest, SetAreaAndGetArea) {
    square->setArea(36.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 36.0);
}

// Test 5: Zero side
TEST_F(SquareTest, ZeroSide) {
    square->setSide(0.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 0.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 0.0);
}

// Test 6: Zero area
TEST_F(SquareTest, ZeroArea) {
    square->setArea(0.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 0.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 0.0);
}

// Test 7: Small decimal side
TEST_F(SquareTest, SmallDecimalSide) {
    square->setSide(0.5);
    EXPECT_DOUBLE_EQ(square->getSide(), 0.5);
    EXPECT_DOUBLE_EQ(square->getArea(), 0.25);
}

// Test 8: Large side value
TEST_F(SquareTest, LargeSideValue) {
    square->setSide(1000.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 1000.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 1000000.0);
}

// Test 9: Very small side
TEST_F(SquareTest, VerySmallSide) {
    square->setSide(0.001);
    EXPECT_NEAR(square->getSide(), 0.001, 1e-9);
    EXPECT_NEAR(square->getArea(), 0.000001, 1e-9);
}

// Test 10: Square root precision
TEST_F(SquareTest, SquareRootPrecision) {
    square->setArea(2.0);
    double expectedSide = std::sqrt(2.0);
    EXPECT_NEAR(square->getSide(), expectedSide, 1e-9);
}

// Test 11: Perfect square area
TEST_F(SquareTest, PerfectSquareArea) {
    square->setArea(144.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 12.0);
}

// Test 12: Non-perfect square area
TEST_F(SquareTest, NonPerfectSquareArea) {
    square->setArea(10.0);
    EXPECT_NEAR(square->getSide(), std::sqrt(10.0), 1e-9);
}

// Test 13: Side to area to side consistency
TEST_F(SquareTest, SideToAreaToSideConsistency) {
    double originalSide = 7.5;
    square->setSide(originalSide);
    double area = square->getArea();
    square->setArea(area);
    EXPECT_NEAR(square->getSide(), originalSide, 1e-9);
}

// Test 14: Area to side to area consistency
TEST_F(SquareTest, AreaToSideToAreaConsistency) {
    double originalArea = 100.0;
    square->setArea(originalArea);
    double side = square->getSide();
    square->setSide(side);
    EXPECT_NEAR(square->getArea(), originalArea, 1e-9);
}

// Test 15: Fractional side
TEST_F(SquareTest, FractionalSide) {
    square->setSide(3.14159);
    EXPECT_DOUBLE_EQ(square->getSide(), 3.14159);
    EXPECT_NEAR(square->getArea(), 9.8696, 0.0001);
}

// Test 16: Multiple operations
TEST_F(SquareTest, MultipleOperations) {
    square->setSide(3.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 9.0);

    square->setArea(16.0);
    EXPECT_DOUBLE_EQ(square->getSide(), 4.0);

    square->setSide(5.0);
    EXPECT_DOUBLE_EQ(square->getArea(), 25.0);
}

// Test 17: Pi squared
TEST_F(SquareTest, PiSquared) {
    square->setSide(M_PI);
    EXPECT_NEAR(square->getArea(), M_PI * M_PI, 1e-9);
}

// Test 18: Very large area
TEST_F(SquareTest, VeryLargeArea) {
    square->setArea(1e10);
    EXPECT_NEAR(square->getSide(), 1e5, 1e-3);
}

// Test 19: Decimal area
TEST_F(SquareTest, DecimalArea) {
    square->setArea(0.25);
    EXPECT_DOUBLE_EQ(square->getSide(), 0.5);
}

// Test 20: Constructor state
TEST_F(SquareTest, ConstructorState) {
    Square newSquare;
    // Just verify it can be constructed and methods can be called
    newSquare.setSide(1.0);
    EXPECT_DOUBLE_EQ(newSquare.getSide(), 1.0);
}
