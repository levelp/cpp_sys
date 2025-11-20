#include <gtest/gtest.h>
#include <string>
#include <sstream>

// Point struct from 05/Points/main.cpp
struct Point {
    std::string name;
    double x, y;
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
    void show() {
        std::cout << name << ": " << x << " " << y << std::endl;
    }
    bool operator <(Point& p) {
        if(x < p.x) return true;
        if(x > p.x) return false;
        return y < p.y;
    }
    Point operator -(Point& p) {
        Point res;
        res.x = x - p.x;
        res.y = y - p.y;
        res.name = name + " - " + p.name;
        return res;
    }
};

// Tests
class PointTest : public ::testing::Test {};

// Test 1: Point initialization
TEST_F(PointTest, Initialization) {
    Point p = {"p", 2.0, 3.0};
    EXPECT_EQ(p.name, "p");
    EXPECT_DOUBLE_EQ(p.x, 2.0);
    EXPECT_DOUBLE_EQ(p.y, 3.0);
}

// Test 2: Move right
TEST_F(PointTest, MoveRight) {
    Point p = {"p", 2.0, 3.0};
    p.move(1.0, 0.0);
    EXPECT_DOUBLE_EQ(p.x, 3.0);
    EXPECT_DOUBLE_EQ(p.y, 3.0);
}

// Test 3: Move up
TEST_F(PointTest, MoveUp) {
    Point p = {"p", 2.0, 3.0};
    p.move(0.0, 1.0);
    EXPECT_DOUBLE_EQ(p.x, 2.0);
    EXPECT_DOUBLE_EQ(p.y, 4.0);
}

// Test 4: Move diagonally
TEST_F(PointTest, MoveDiagonally) {
    Point p = {"p", 2.0, 3.0};
    p.move(1.0, 1.0);
    EXPECT_DOUBLE_EQ(p.x, 3.0);
    EXPECT_DOUBLE_EQ(p.y, 4.0);
}

// Test 5: Move with negative values
TEST_F(PointTest, MoveNegative) {
    Point p = {"p", 2.0, 3.0};
    p.move(-1.0, -1.0);
    EXPECT_DOUBLE_EQ(p.x, 1.0);
    EXPECT_DOUBLE_EQ(p.y, 2.0);
}

// Test 6: Comparison - less than (x coordinate)
TEST_F(PointTest, ComparisonLessThanX) {
    Point p1 = {"p1", 1.0, 5.0};
    Point p2 = {"p2", 2.0, 3.0};
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p2 < p1);
}

// Test 7: Comparison - less than (y coordinate when x equal)
TEST_F(PointTest, ComparisonLessThanY) {
    Point p1 = {"p1", 2.0, 3.0};
    Point p2 = {"p2", 2.0, 4.0};
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p2 < p1);
}

// Test 8: Comparison - equal points
TEST_F(PointTest, ComparisonEqual) {
    Point p1 = {"p1", 2.0, 3.0};
    Point p2 = {"p2", 2.0, 3.0};
    EXPECT_FALSE(p1 < p2);
    EXPECT_FALSE(p2 < p1);
}

// Test 9: Subtraction operator
TEST_F(PointTest, Subtraction) {
    Point A = {"A", 3.0, 4.0};
    Point p = {"p", 2.0, 3.0};
    Point diff = A - p;
    EXPECT_DOUBLE_EQ(diff.x, 1.0);
    EXPECT_DOUBLE_EQ(diff.y, 1.0);
    EXPECT_EQ(diff.name, "A - p");
}

// Test 10: Subtraction resulting in negative
TEST_F(PointTest, SubtractionNegative) {
    Point p1 = {"p1", 1.0, 2.0};
    Point p2 = {"p2", 3.0, 5.0};
    Point diff = p1 - p2;
    EXPECT_DOUBLE_EQ(diff.x, -2.0);
    EXPECT_DOUBLE_EQ(diff.y, -3.0);
}

// Test 11: Subtraction with zero
TEST_F(PointTest, SubtractionWithZero) {
    Point p = {"p", 5.0, 7.0};
    Point origin = {"origin", 0.0, 0.0};
    Point diff = p - origin;
    EXPECT_DOUBLE_EQ(diff.x, 5.0);
    EXPECT_DOUBLE_EQ(diff.y, 7.0);
}

// Test 12: Move to origin
TEST_F(PointTest, MoveToOrigin) {
    Point p = {"p", 5.0, 3.0};
    p.move(-5.0, -3.0);
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

// Test 13: Multiple moves
TEST_F(PointTest, MultipleMoves) {
    Point p = {"p", 0.0, 0.0};
    p.move(1.0, 0.0);
    p.move(0.0, 1.0);
    p.move(1.0, 1.0);
    EXPECT_DOUBLE_EQ(p.x, 2.0);
    EXPECT_DOUBLE_EQ(p.y, 2.0);
}

// Test 14: Large coordinates
TEST_F(PointTest, LargeCoordinates) {
    Point p = {"p", 1000.0, 2000.0};
    EXPECT_DOUBLE_EQ(p.x, 1000.0);
    EXPECT_DOUBLE_EQ(p.y, 2000.0);
}

// Test 15: Decimal coordinates
TEST_F(PointTest, DecimalCoordinates) {
    Point p = {"p", 1.5, 2.7};
    EXPECT_DOUBLE_EQ(p.x, 1.5);
    EXPECT_DOUBLE_EQ(p.y, 2.7);
}

// Test 16: Negative coordinates
TEST_F(PointTest, NegativeCoordinates) {
    Point p = {"p", -5.0, -10.0};
    EXPECT_DOUBLE_EQ(p.x, -5.0);
    EXPECT_DOUBLE_EQ(p.y, -10.0);
}

// Test 17: Move by zero
TEST_F(PointTest, MoveByZero) {
    Point p = {"p", 3.0, 4.0};
    p.move(0.0, 0.0);
    EXPECT_DOUBLE_EQ(p.x, 3.0);
    EXPECT_DOUBLE_EQ(p.y, 4.0);
}

// Test 18: Comparison with negative coordinates
TEST_F(PointTest, ComparisonNegative) {
    Point p1 = {"p1", -2.0, 3.0};
    Point p2 = {"p2", -1.0, 3.0};
    EXPECT_TRUE(p1 < p2);
}

// Test 19: Origin point
TEST_F(PointTest, OriginPoint) {
    Point origin = {"origin", 0.0, 0.0};
    EXPECT_DOUBLE_EQ(origin.x, 0.0);
    EXPECT_DOUBLE_EQ(origin.y, 0.0);
}

// Test 20: Subtraction same point
TEST_F(PointTest, SubtractionSamePoint) {
    Point p1 = {"p", 5.0, 5.0};
    Point p2 = {"p", 5.0, 5.0};
    Point diff = p1 - p2;
    EXPECT_DOUBLE_EQ(diff.x, 0.0);
    EXPECT_DOUBLE_EQ(diff.y, 0.0);
}

// Test 21: Name concatenation in subtraction
TEST_F(PointTest, NameConcatenation) {
    Point A = {"Alpha", 10.0, 20.0};
    Point B = {"Beta", 5.0, 10.0};
    Point diff = A - B;
    EXPECT_EQ(diff.name, "Alpha - Beta");
}

// Test 22: Very small decimal moves
TEST_F(PointTest, SmallDecimalMoves) {
    Point p = {"p", 0.0, 0.0};
    p.move(0.001, 0.001);
    EXPECT_NEAR(p.x, 0.001, 1e-9);
    EXPECT_NEAR(p.y, 0.001, 1e-9);
}

// Test 23: Comparison with same x, different y
TEST_F(PointTest, ComparisonSameX) {
    Point p1 = {"p1", 5.0, 1.0};
    Point p2 = {"p2", 5.0, 10.0};
    EXPECT_TRUE(p1 < p2);
}

// Test 24: Large move values
TEST_F(PointTest, LargeMoves) {
    Point p = {"p", 0.0, 0.0};
    p.move(1000.0, 2000.0);
    EXPECT_DOUBLE_EQ(p.x, 1000.0);
    EXPECT_DOUBLE_EQ(p.y, 2000.0);
}

// Test 25: Complex scenario
TEST_F(PointTest, ComplexScenario) {
    Point p = {"p", 2.0, 3.0};
    Point A = {"A", 3.0, 4.0};

    p.move(1.0, 0.0);
    EXPECT_DOUBLE_EQ(p.x, 3.0);

    Point diff = A - p;
    EXPECT_DOUBLE_EQ(diff.x, 0.0);
    EXPECT_DOUBLE_EQ(diff.y, 1.0);
}
