#include <gtest/gtest.h>
#include <sstream>
#include <cmath>

// Include the Rational class from the original file
// We'll copy the template class definition here for testing
template <class T = int>
class Rational {
    T p, q;
    T GCD(T, T);
    void normalize();
public:
    Rational(T pi = 0, T qi = 1);
    T getP() { return p; }
    T getQ() { return q; }

    Rational operator +(Rational&);
    Rational operator -(Rational&);
    Rational operator *(Rational&);
    Rational operator /(Rational&);

    template <class Q>
    friend std::ostream& operator <<(std::ostream& os, Rational<Q> r);
};

template <class T>
T Rational<T>::GCD(T a, T b) {
    return (b == 0) ? a : GCD(b, a % b);
}

template <class T>
void Rational<T>::normalize() {
    T d = GCD(std::abs(p), std::abs(q));
    p /= d;
    q /= d;
}

template <class T>
Rational<T>::Rational(T pi, T qi) : p(pi), q(qi) {
    if(q == 0) throw std::invalid_argument("Denominator cannot be zero");
}

template <class T>
Rational<T> Rational<T>::operator +(Rational<T>& right) {
    return Rational(
        p * right.q + right.p * q,
        q * right.q);
}

template <class T>
Rational<T> Rational<T>::operator -(Rational& right) {
    return Rational(
        p * right.q - right.p * q,
        q * right.q);
}

template <class T>
Rational<T> Rational<T>::operator *(Rational<T>& right) {
    return Rational(
        p * right.p,
        q * right.q);
}

template <class T>
Rational<T> Rational<T>::operator /(Rational& right) {
    return Rational(
        p * right.q,
        q * right.p);
}

template <class T>
std::ostream& operator <<(std::ostream& os, Rational<T> r) {
    r.normalize();
    if(r.q == 1)
        os << r.p;
    else {
        T whole = r.p / r.q;
        if(whole != 0)
            os << whole << " ";
        if(whole != 0)
            os << std::abs(r.p % r.q);
        else
            os << (r.p % r.q);
        os << "/" << r.q;
    }
    return os;
}

// Tests
class RationalTest : public ::testing::Test {};

// Test 1: Constructor with default values
TEST_F(RationalTest, ConstructorDefault) {
    Rational<int> r;
    EXPECT_EQ(r.getP(), 0);
    EXPECT_EQ(r.getQ(), 1);
}

// Test 2: Constructor with custom values
TEST_F(RationalTest, ConstructorCustom) {
    Rational<int> r(3, 4);
    EXPECT_EQ(r.getP(), 3);
    EXPECT_EQ(r.getQ(), 4);
}

// Test 3: Zero denominator throws exception
TEST_F(RationalTest, ZeroDenominatorThrows) {
    EXPECT_THROW(Rational<int>(5, 0), std::invalid_argument);
}

// Test 4: GCD calculation through normalization
TEST_F(RationalTest, GCDNormalization) {
    Rational<int> r(4, 6);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "2/3");
}

// Test 5: Addition of fractions
TEST_F(RationalTest, Addition) {
    Rational<int> a(1, 2), b(1, 3);
    Rational<int> c = a + b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "5/6");
}

// Test 6: Subtraction of fractions
TEST_F(RationalTest, Subtraction) {
    Rational<int> a(1, 2), b(1, 3);
    Rational<int> c = a - b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "1/6");
}

// Test 7: Multiplication of fractions
TEST_F(RationalTest, Multiplication) {
    Rational<int> a(2, 3), b(3, 4);
    Rational<int> c = a * b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "1/2");
}

// Test 8: Division of fractions
TEST_F(RationalTest, Division) {
    Rational<int> a(1, 2), b(1, 4);
    Rational<int> c = a / b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "2");
}

// Test 9: Negative numerator
TEST_F(RationalTest, NegativeNumerator) {
    Rational<int> r(-3, 4);
    EXPECT_EQ(r.getP(), -3);
    EXPECT_EQ(r.getQ(), 4);
}

// Test 10: Whole number representation
TEST_F(RationalTest, WholeNumber) {
    Rational<int> r(6, 3);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "2");
}

// Test 11: Improper fraction
TEST_F(RationalTest, ImproperFraction) {
    Rational<int> r(7, 3);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "2 1/3");
}

// Test 12: Zero numerator
TEST_F(RationalTest, ZeroNumerator) {
    Rational<int> r(0, 5);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "0");
}

// Test 13: Same numerator and denominator
TEST_F(RationalTest, SameNumeratorDenominator) {
    Rational<int> r(5, 5);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "1");
}

// Test 14: Long type
TEST_F(RationalTest, LongType) {
    Rational<long> r(1000000L, 2000000L);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "1/2");
}

// Test 15: Addition with negative
TEST_F(RationalTest, AdditionNegative) {
    Rational<int> a(-5, 3), b(-3, 3);
    Rational<int> c = a + b;
    std::ostringstream oss;
    oss << c;
    // -5/3 + -3/3 = -8/3 = -2 2/3
    EXPECT_EQ(oss.str(), "-2 2/3");
}

// Test 16: Subtraction resulting in negative
TEST_F(RationalTest, SubtractionNegative) {
    Rational<int> a(1, 3), b(2, 3);
    Rational<int> c = a - b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "-1/3");
}

// Test 17: Chain addition
TEST_F(RationalTest, ChainAddition) {
    Rational<long> x(-5, 3), y(-3, 3), z(5, 6);
    Rational<long> t1 = x + y;
    Rational<long> t = t1 + z;
    std::ostringstream oss;
    oss << t;
    // -5/3 + -3/3 + 5/6 = -8/3 + 5/6 = -16/6 + 5/6 = -11/6 = -1 5/6
    EXPECT_EQ(oss.str(), "-1 5/6");
}

// Test 18: Multiplication with negatives
TEST_F(RationalTest, MultiplicationNegative) {
    Rational<int> a(-2, 3), b(3, 4);
    Rational<int> c = a * b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "-1/2");
}

// Test 19: Division by larger fraction
TEST_F(RationalTest, DivisionByLarger) {
    Rational<int> a(1, 2), b(3, 4);
    Rational<int> c = a / b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "2/3");
}

// Test 20: Getters work correctly
TEST_F(RationalTest, Getters) {
    Rational<int> r(7, 9);
    EXPECT_EQ(r.getP(), 7);
    EXPECT_EQ(r.getQ(), 9);
}

// Test 21: Addition of integers as rationals
TEST_F(RationalTest, IntegerAddition) {
    Rational<int> a(4, 1), b(5, 1);
    Rational<int> c = a + b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "9");
}

// Test 22: Fraction simplification
TEST_F(RationalTest, FractionSimplification) {
    Rational<int> r(12, 18);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "2/3");
}

// Test 23: Large GCD
TEST_F(RationalTest, LargeGCD) {
    Rational<int> r(100, 150);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "2/3");
}

// Test 24: Prime numbers (no simplification)
TEST_F(RationalTest, PrimeNumbers) {
    Rational<int> r(7, 11);
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "7/11");
}

// Test 25: Multiplication resulting in whole number
TEST_F(RationalTest, MultiplicationWholeNumber) {
    Rational<int> a(2, 3), b(3, 2);
    Rational<int> c = a * b;
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "1");
}
