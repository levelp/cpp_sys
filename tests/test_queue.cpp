#include <gtest/gtest.h>
#include <climits>
#include "../07/02_StackTemplate/queue.h"

class QueueTest : public ::testing::Test {
protected:
    Queue<int>* intQueue;

    void SetUp() override {
        intQueue = new Queue<int>();
    }

    void TearDown() override {
        delete intQueue;
    }
};

// Test 1: Empty queue throws exception
TEST_F(QueueTest, EmptyQueueThrowsException) {
    EXPECT_THROW(intQueue->get(), const char*);
}

// Test 2: Constructor creates queue
TEST_F(QueueTest, ConstructorCreatesQueue) {
    Queue<int> q;
    EXPECT_THROW(q.get(), const char*);
}

// Test 3: Can put single element (tests put method)
TEST_F(QueueTest, CanPutSingleElement) {
    intQueue->put(42);
    // If we got here without crash, put() works for single element
    EXPECT_NO_THROW(intQueue->put(42));
}

// Test 4: Can create queue with different types
TEST_F(QueueTest, DifferentTypes) {
    Queue<double> dq;
    Queue<std::string> sq;
    EXPECT_THROW(dq.get(), const char*);
    EXPECT_THROW(sq.get(), const char*);
}
