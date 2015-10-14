#include <gtest/gtest.h>
#include <string>

// Stack template from 05/15_template_stack_in_array/main.cpp
template <class T, int size>
class Stack {
    T d[size];
    int N;
public:
    Stack() : N(0) {}
    void push(T value) {
        if(isFull()) throw std::string("Stack is full");
        d[N++] = value;
    }
    T pop() {
        if(isEmpty()) throw std::string("Stack is empty");
        return d[--N];
    }
    bool isEmpty() {
        return N == 0;
    }
    bool isFull() {
        return N == size;
    }
};

// Tests
class StackTest : public ::testing::Test {};

// Test 1: New stack is empty
TEST_F(StackTest, NewStackIsEmpty) {
    Stack<int, 10> s;
    EXPECT_TRUE(s.isEmpty());
    EXPECT_FALSE(s.isFull());
}

// Test 2: Push and pop single element
TEST_F(StackTest, PushPopSingle) {
    Stack<int, 10> s;
    s.push(42);
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.pop(), 42);
    EXPECT_TRUE(s.isEmpty());
}

// Test 3: LIFO order
TEST_F(StackTest, LIFOOrder) {
    Stack<int, 10> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
}

// Test 4: Pop from empty stack throws
TEST_F(StackTest, PopEmptyThrows) {
    Stack<int, 5> s;
    EXPECT_THROW(s.pop(), std::string);
}

// Test 5: Push to full stack throws
TEST_F(StackTest, PushFullThrows) {
    Stack<int, 3> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_TRUE(s.isFull());
    EXPECT_THROW(s.push(4), std::string);
}

// Test 6: Fill stack to capacity
TEST_F(StackTest, FillToCapacity) {
    Stack<int, 5> s;
    for(int i = 0; i < 5; i++) {
        s.push(i);
    }
    EXPECT_TRUE(s.isFull());
    EXPECT_FALSE(s.isEmpty());
}

// Test 7: Empty after filling and emptying
TEST_F(StackTest, EmptyAfterFillingAndEmptying) {
    Stack<int, 5> s;
    for(int i = 0; i < 5; i++) {
        s.push(i);
    }
    for(int i = 0; i < 5; i++) {
        s.pop();
    }
    EXPECT_TRUE(s.isEmpty());
}

// Test 8: String stack
TEST_F(StackTest, StringStack) {
    Stack<std::string, 3> s;
    s.push("hello");
    s.push("world");
    EXPECT_EQ(s.pop(), "world");
    EXPECT_EQ(s.pop(), "hello");
}

// Test 9: Double stack
TEST_F(StackTest, DoubleStack) {
    Stack<double, 5> s;
    s.push(3.14);
    s.push(2.71);
    EXPECT_DOUBLE_EQ(s.pop(), 2.71);
    EXPECT_DOUBLE_EQ(s.pop(), 3.14);
}

// Test 10: Alternating push and pop
TEST_F(StackTest, AlternatingPushPop) {
    Stack<int, 10> s;
    s.push(1);
    EXPECT_EQ(s.pop(), 1);
    s.push(2);
    EXPECT_EQ(s.pop(), 2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
}

// Test 11: Size 1 stack
TEST_F(StackTest, Size1Stack) {
    Stack<int, 1> s;
    s.push(42);
    EXPECT_TRUE(s.isFull());
    EXPECT_EQ(s.pop(), 42);
    EXPECT_TRUE(s.isEmpty());
}

// Test 12: Large capacity
TEST_F(StackTest, LargeCapacity) {
    Stack<int, 1000> s;
    for(int i = 0; i < 1000; i++) {
        s.push(i);
    }
    EXPECT_TRUE(s.isFull());
    for(int i = 999; i >= 0; i--) {
        EXPECT_EQ(s.pop(), i);
    }
}

// Test 13: Negative numbers
TEST_F(StackTest, NegativeNumbers) {
    Stack<int, 5> s;
    s.push(-1);
    s.push(-10);
    s.push(-100);
    EXPECT_EQ(s.pop(), -100);
    EXPECT_EQ(s.pop(), -10);
    EXPECT_EQ(s.pop(), -1);
}

// Test 14: Zero values
TEST_F(StackTest, ZeroValues) {
    Stack<int, 3> s;
    s.push(0);
    s.push(0);
    s.push(0);
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), 0);
}

// Test 15: Mixed values
TEST_F(StackTest, MixedValues) {
    Stack<int, 5> s;
    s.push(-5);
    s.push(0);
    s.push(10);
    EXPECT_EQ(s.pop(), 10);
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), -5);
}

// Test 16: Boolean stack
TEST_F(StackTest, BooleanStack) {
    Stack<bool, 4> s;
    s.push(true);
    s.push(false);
    s.push(true);
    EXPECT_EQ(s.pop(), true);
    EXPECT_EQ(s.pop(), false);
    EXPECT_EQ(s.pop(), true);
}

// Test 17: Char stack
TEST_F(StackTest, CharStack) {
    Stack<char, 5> s;
    s.push('a');
    s.push('b');
    s.push('c');
    EXPECT_EQ(s.pop(), 'c');
    EXPECT_EQ(s.pop(), 'b');
    EXPECT_EQ(s.pop(), 'a');
}

// Test 18: Partial fill
TEST_F(StackTest, PartialFill) {
    Stack<int, 10> s;
    s.push(1);
    s.push(2);
    EXPECT_FALSE(s.isEmpty());
    EXPECT_FALSE(s.isFull());
}

// Test 19: Exception message check
TEST_F(StackTest, ExceptionMessageEmpty) {
    Stack<int, 5> s;
    try {
        s.pop();
        FAIL() << "Expected exception";
    } catch(const std::string& e) {
        EXPECT_EQ(e, "Stack is empty");
    }
}

// Test 20: Exception message check full
TEST_F(StackTest, ExceptionMessageFull) {
    Stack<int, 2> s;
    s.push(1);
    s.push(2);
    try {
        s.push(3);
        FAIL() << "Expected exception";
    } catch(const std::string& e) {
        EXPECT_EQ(e, "Stack is full");
    }
}
