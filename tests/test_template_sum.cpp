#include <gtest/gtest.h>
#include <string>
#include <sstream>

// Template function from 05/04_template_sum/main.cpp
template <class T>
T sumArray(T array[], size_t size) {
    T sum = 0;
    for(size_t i = 0; i < size; ++i)
        sum += array[i];
    return sum;
}

// Template specialization for strings
template <>
std::string sumArray(std::string array[], size_t size) {
    std::string sum = "";
    for(size_t i = 0; i < size; ++i)
        sum += array[i];
    return sum;
}

// Complex number class
struct Complex {
private:
    double re, im;
public:
    Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}

    Complex operator +=(Complex& right) {
        this->re += right.re;
        this->im += right.im;
        return *this;
    }

    Complex operator +(Complex& right) {
        Complex res = *this;
        res += right;
        return res;
    }

    double getReal() const { return re; }
    double getImag() const { return im; }

    friend std::ostream& operator <<(std::ostream& os, Complex c);
};

std::ostream& operator <<(std::ostream& os, Complex c) {
    os << c.re << " + " << c.im << "i ";
    return os;
}

// Tests
class TemplateSumTest : public ::testing::Test {};

// Test 1: Sum integer array
TEST_F(TemplateSumTest, SumIntArray) {
    int a[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(sumArray(a, 5), 15);
}

// Test 2: Sum double array
TEST_F(TemplateSumTest, SumDoubleArray) {
    double d[] = {1.5, 2.5, 3.0};
    EXPECT_DOUBLE_EQ(sumArray(d, 3), 7.0);
}

// Test 3: Sum long long array
TEST_F(TemplateSumTest, SumLongLongArray) {
    long long ll[] = {1000000000LL, 2000000000LL, 3000000000LL};
    EXPECT_EQ(sumArray(ll, 3), 6000000000LL);
}

// Test 4: Concatenate strings
TEST_F(TemplateSumTest, ConcatenateStrings) {
    std::string sa[] = {"Hello, ", "World", "!"};
    EXPECT_EQ(sumArray(sa, 3), "Hello, World!");
}

// Test 5: Sum complex numbers
TEST_F(TemplateSumTest, SumComplexNumbers) {
    Complex ca[] = {Complex(1.0, 0.0), Complex(2.0, 3.0), Complex(3.0, 4.0)};
    Complex result = sumArray(ca, 3);
    EXPECT_DOUBLE_EQ(result.getReal(), 6.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 7.0);
}

// Test 6: Empty integer array
TEST_F(TemplateSumTest, EmptyIntArray) {
    int a[] = {};
    EXPECT_EQ(sumArray(a, 0), 0);
}

// Test 7: Single element integer
TEST_F(TemplateSumTest, SingleElementInt) {
    int a[] = {42};
    EXPECT_EQ(sumArray(a, 1), 42);
}

// Test 8: Negative integers
TEST_F(TemplateSumTest, NegativeIntegers) {
    int a[] = {-1, -2, -3};
    EXPECT_EQ(sumArray(a, 3), -6);
}

// Test 9: Mixed positive and negative
TEST_F(TemplateSumTest, MixedSignIntegers) {
    int a[] = {10, -5, 20, -10};
    EXPECT_EQ(sumArray(a, 4), 15);
}

// Test 10: All zeros
TEST_F(TemplateSumTest, AllZeros) {
    int a[] = {0, 0, 0, 0};
    EXPECT_EQ(sumArray(a, 4), 0);
}

// Test 11: Large integer values
TEST_F(TemplateSumTest, LargeIntegerValues) {
    int a[] = {1000, 2000, 3000};
    EXPECT_EQ(sumArray(a, 3), 6000);
}

// Test 12: Decimal precision for doubles
TEST_F(TemplateSumTest, DoublePrecision) {
    double d[] = {0.1, 0.2, 0.3};
    EXPECT_NEAR(sumArray(d, 3), 0.6, 0.0001);
}

// Test 13: String concatenation order
TEST_F(TemplateSumTest, StringConcatenationOrder) {
    std::string sa[] = {"First", "Second", "Third"};
    EXPECT_EQ(sumArray(sa, 3), "FirstSecondThird");
}

// Test 14: Empty string in array
TEST_F(TemplateSumTest, EmptyStringInArray) {
    std::string sa[] = {"Hello", "", "World"};
    EXPECT_EQ(sumArray(sa, 3), "HelloWorld");
}

// Test 15: Single string
TEST_F(TemplateSumTest, SingleString) {
    std::string sa[] = {"OnlyOne"};
    EXPECT_EQ(sumArray(sa, 1), "OnlyOne");
}

// Test 16: Complex with zero imaginary
TEST_F(TemplateSumTest, ComplexZeroImaginary) {
    Complex ca[] = {Complex(1.0, 0.0), Complex(2.0, 0.0)};
    Complex result = sumArray(ca, 2);
    EXPECT_DOUBLE_EQ(result.getReal(), 3.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 0.0);
}

// Test 17: Complex with zero real
TEST_F(TemplateSumTest, ComplexZeroReal) {
    Complex ca[] = {Complex(0.0, 1.0), Complex(0.0, 2.0)};
    Complex result = sumArray(ca, 2);
    EXPECT_DOUBLE_EQ(result.getReal(), 0.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 3.0);
}

// Test 18: Complex negative values
TEST_F(TemplateSumTest, ComplexNegativeValues) {
    Complex ca[] = {Complex(-1.0, -2.0), Complex(-3.0, -4.0)};
    Complex result = sumArray(ca, 2);
    EXPECT_DOUBLE_EQ(result.getReal(), -4.0);
    EXPECT_DOUBLE_EQ(result.getImag(), -6.0);
}

// Test 19: Complex mixed signs
TEST_F(TemplateSumTest, ComplexMixedSigns) {
    Complex ca[] = {Complex(5.0, -3.0), Complex(-2.0, 7.0)};
    Complex result = sumArray(ca, 2);
    EXPECT_DOUBLE_EQ(result.getReal(), 3.0);
    EXPECT_DOUBLE_EQ(result.getImag(), 4.0);
}

// Test 20: Float array
TEST_F(TemplateSumTest, FloatArray) {
    float f[] = {1.5f, 2.5f, 3.5f};
    EXPECT_FLOAT_EQ(sumArray(f, 3), 7.5f);
}

// Test 21: Short array
TEST_F(TemplateSumTest, ShortArray) {
    short s[] = {10, 20, 30};
    EXPECT_EQ(sumArray(s, 3), 60);
}

// Test 22: Complex operator output
TEST_F(TemplateSumTest, ComplexOutput) {
    Complex c(3.5, 2.5);
    std::ostringstream oss;
    oss << c;
    EXPECT_EQ(oss.str(), "3.5 + 2.5i ");
}

// Test 23: Complex default constructor
TEST_F(TemplateSumTest, ComplexDefaultConstructor) {
    Complex c;
    EXPECT_DOUBLE_EQ(c.getReal(), 0.0);
    EXPECT_DOUBLE_EQ(c.getImag(), 0.0);
}

// Test 24: Complex addition operator
TEST_F(TemplateSumTest, ComplexAdditionOperator) {
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex c = a + b;
    EXPECT_DOUBLE_EQ(c.getReal(), 4.0);
    EXPECT_DOUBLE_EQ(c.getImag(), 6.0);
}

// Test 25: Complex += operator
TEST_F(TemplateSumTest, ComplexPlusEqualsOperator) {
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    a += b;
    EXPECT_DOUBLE_EQ(a.getReal(), 4.0);
    EXPECT_DOUBLE_EQ(a.getImag(), 6.0);
}

// Test 26: Large complex array
TEST_F(TemplateSumTest, LargeComplexArray) {
    Complex ca[10];
    for(int i = 0; i < 10; i++) {
        ca[i] = Complex(i, i * 0.5);
    }
    Complex result = sumArray(ca, 10);
    EXPECT_DOUBLE_EQ(result.getReal(), 45.0);  // 0+1+2+...+9
    EXPECT_DOUBLE_EQ(result.getImag(), 22.5);  // 0+0.5+1.0+...+4.5
}

// Test 27: String with spaces
TEST_F(TemplateSumTest, StringWithSpaces) {
    std::string sa[] = {"Hello ", "World ", "Test"};
    EXPECT_EQ(sumArray(sa, 3), "Hello World Test");
}

// Test 28: Very long string concatenation
TEST_F(TemplateSumTest, LongStringConcatenation) {
    std::string sa[5];
    for(int i = 0; i < 5; i++) {
        sa[i] = "Part" + std::to_string(i) + " ";
    }
    std::string result = sumArray(sa, 5);
    EXPECT_EQ(result, "Part0 Part1 Part2 Part3 Part4 ");
}

// Test 29: Sum with overflow check (within int range)
TEST_F(TemplateSumTest, NoOverflowInIntRange) {
    int a[] = {100, 200, 300};
    EXPECT_EQ(sumArray(a, 3), 600);
}

// Test 30: Empty string array
TEST_F(TemplateSumTest, EmptyStringArray) {
    std::string sa[] = {};
    EXPECT_EQ(sumArray(sa, 0), "");
}
