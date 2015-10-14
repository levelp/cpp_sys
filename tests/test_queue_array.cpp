#include <gtest/gtest.h>

// Queue class from 04/00_queue/main.cpp
class QueueArray {
    const static int SIZE = 100;
    int data[SIZE];
    int head = 0;
    int tail = -1;
public:
    void put(int v) {
        ++tail;
        data[tail] = v;
    }
    int get() {
        return data[head++];
    }
    int size() {
        return tail - head + 1;
    }
};

// Tests
class QueueArrayTest : public ::testing::Test {};

// Test 1: Initial size is 0
TEST_F(QueueArrayTest, InitialSizeIsZero) {
    QueueArray q;
    EXPECT_EQ(q.size(), 0);
}

// Test 2: Put and get single element
TEST_F(QueueArrayTest, PutGetSingle) {
    QueueArray q;
    q.put(42);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.get(), 42);
    EXPECT_EQ(q.size(), 0);
}

// Test 3: FIFO order
TEST_F(QueueArrayTest, FIFOOrder) {
    QueueArray q;
    q.put(1);
    q.put(2);
    q.put(3);
    EXPECT_EQ(q.get(), 1);
    EXPECT_EQ(q.get(), 2);
    EXPECT_EQ(q.get(), 3);
}

// Test 4: Size increases with put
TEST_F(QueueArrayTest, SizeIncreasesWithPut) {
    QueueArray q;
    EXPECT_EQ(q.size(), 0);
    q.put(1);
    EXPECT_EQ(q.size(), 1);
    q.put(2);
    EXPECT_EQ(q.size(), 2);
    q.put(3);
    EXPECT_EQ(q.size(), 3);
}

// Test 5: Size decreases with get
TEST_F(QueueArrayTest, SizeDecreasesWithGet) {
    QueueArray q;
    q.put(1);
    q.put(2);
    q.put(3);
    EXPECT_EQ(q.size(), 3);
    q.get();
    EXPECT_EQ(q.size(), 2);
    q.get();
    EXPECT_EQ(q.size(), 1);
    q.get();
    EXPECT_EQ(q.size(), 0);
}

// Test 6: Interleaved put and get
TEST_F(QueueArrayTest, InterleavedPutGet) {
    QueueArray q;
    q.put(1);
    q.put(2);
    EXPECT_EQ(q.get(), 1);
    q.put(3);
    EXPECT_EQ(q.get(), 2);
    EXPECT_EQ(q.get(), 3);
}

// Test 7: Multiple sequences
TEST_F(QueueArrayTest, MultipleSequences) {
    QueueArray q;
    // First sequence
    q.put(10);
    q.put(20);
    EXPECT_EQ(q.get(), 10);
    EXPECT_EQ(q.get(), 20);

    // Second sequence
    q.put(30);
    q.put(40);
    q.put(50);
    EXPECT_EQ(q.get(), 30);
    EXPECT_EQ(q.get(), 40);
    EXPECT_EQ(q.get(), 50);
}

// Test 8: Large number of elements
TEST_F(QueueArrayTest, LargeNumberOfElements) {
    QueueArray q;
    for(int i = 0; i < 50; i++) {
        q.put(i);
    }
    EXPECT_EQ(q.size(), 50);
    for(int i = 0; i < 50; i++) {
        EXPECT_EQ(q.get(), i);
    }
    EXPECT_EQ(q.size(), 0);
}

// Test 9: Negative numbers
TEST_F(QueueArrayTest, NegativeNumbers) {
    QueueArray q;
    q.put(-1);
    q.put(-10);
    q.put(-100);
    EXPECT_EQ(q.get(), -1);
    EXPECT_EQ(q.get(), -10);
    EXPECT_EQ(q.get(), -100);
}

// Test 10: Zero values
TEST_F(QueueArrayTest, ZeroValues) {
    QueueArray q;
    q.put(0);
    q.put(0);
    q.put(0);
    EXPECT_EQ(q.get(), 0);
    EXPECT_EQ(q.get(), 0);
    EXPECT_EQ(q.get(), 0);
}

// Test 11: Mixed positive and negative
TEST_F(QueueArrayTest, MixedValues) {
    QueueArray q;
    q.put(10);
    q.put(-5);
    q.put(0);
    q.put(15);
    EXPECT_EQ(q.get(), 10);
    EXPECT_EQ(q.get(), -5);
    EXPECT_EQ(q.get(), 0);
    EXPECT_EQ(q.get(), 15);
}

// Test 12: Size after partial get
TEST_F(QueueArrayTest, SizeAfterPartialGet) {
    QueueArray q;
    q.put(1);
    q.put(2);
    q.put(3);
    q.put(4);
    q.put(5);
    q.get();
    q.get();
    EXPECT_EQ(q.size(), 3);
}

// Test 13: Alternating operations
TEST_F(QueueArrayTest, AlternatingOperations) {
    QueueArray q;
    for(int i = 0; i < 10; i++) {
        q.put(i);
        if(i > 0 && i % 2 == 0) {
            q.get();
        }
    }
    EXPECT_GT(q.size(), 0);
}

// Test 14: Large values
TEST_F(QueueArrayTest, LargeValues) {
    QueueArray q;
    q.put(1000000);
    q.put(2000000);
    q.put(3000000);
    EXPECT_EQ(q.get(), 1000000);
    EXPECT_EQ(q.get(), 2000000);
    EXPECT_EQ(q.get(), 3000000);
}

// Test 15: Sequential batch operations
TEST_F(QueueArrayTest, SequentialBatchOperations) {
    QueueArray q;
    // Batch 1
    for(int i = 0; i < 5; i++) q.put(i);
    for(int i = 0; i < 5; i++) EXPECT_EQ(q.get(), i);

    // Batch 2
    for(int i = 5; i < 10; i++) q.put(i);
    for(int i = 5; i < 10; i++) EXPECT_EQ(q.get(), i);
}
