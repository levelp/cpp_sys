#include <gtest/gtest.h>

// Element structure from 04/02_stack_OOP/main.cpp
struct E {
    int value;
    E* next;
};

// Stack with linked list
struct StackLinked {
    E* top;
    StackLinked() : top(NULL) {}
    void push(int value) {
        E* newElement = new E;
        newElement->value = value;
        newElement->next = top;
        top = newElement;
    }
    int pop() {
        int result = top->value;
        E* e = top;
        top = top->next;
        delete e;
        return result;
    }
    bool isEmpty() { return top == NULL; }
    ~StackLinked() {
        while(top != NULL) {
            E* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Queue with linked list
struct QueueLinked {
    E* head;
    E* tail;
    QueueLinked() : head(NULL), tail(NULL) {}
    void put(int value) {
        E* e = new E;
        e->value = value;
        e->next = NULL;
        if(head == NULL) {
            head = e;
            tail = e;
        } else {
            tail->next = e;
            tail = e;
        }
    }
    int get() {
        E* firstElement = head;
        int value = firstElement->value;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        delete firstElement;
        return value;
    }
    bool isEmpty() { return head == NULL; }
    ~QueueLinked() {
        while(head != NULL) {
            E* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Tests for StackLinked
class StackLinkedTest : public ::testing::Test {};

TEST_F(StackLinkedTest, PushAndPop) {
    StackLinked s;
    s.push(10);
    EXPECT_EQ(s.pop(), 10);
}

TEST_F(StackLinkedTest, LIFOOrder) {
    StackLinked s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
}

TEST_F(StackLinkedTest, MultiplePushPop) {
    StackLinked s;
    s.push(5);
    s.push(10);
    EXPECT_EQ(s.pop(), 10);
    s.push(15);
    EXPECT_EQ(s.pop(), 15);
    EXPECT_EQ(s.pop(), 5);
}

TEST_F(StackLinkedTest, LargeSequence) {
    StackLinked s;
    for(int i = 0; i < 100; i++) {
        s.push(i);
    }
    for(int i = 99; i >= 0; i--) {
        EXPECT_EQ(s.pop(), i);
    }
}

TEST_F(StackLinkedTest, NegativeValues) {
    StackLinked s;
    s.push(-1);
    s.push(-10);
    s.push(-100);
    EXPECT_EQ(s.pop(), -100);
    EXPECT_EQ(s.pop(), -10);
    EXPECT_EQ(s.pop(), -1);
}

TEST_F(StackLinkedTest, ZeroValues) {
    StackLinked s;
    s.push(0);
    s.push(0);
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), 0);
}

TEST_F(StackLinkedTest, MixedValues) {
    StackLinked s;
    s.push(10);
    s.push(-5);
    s.push(0);
    EXPECT_EQ(s.pop(), 0);
    EXPECT_EQ(s.pop(), -5);
    EXPECT_EQ(s.pop(), 10);
}

TEST_F(StackLinkedTest, SingleElement) {
    StackLinked s;
    s.push(42);
    EXPECT_EQ(s.pop(), 42);
}

TEST_F(StackLinkedTest, AlternatingPushPop) {
    StackLinked s;
    for(int i = 0; i < 10; i++) {
        s.push(i);
        EXPECT_EQ(s.pop(), i);
    }
}

TEST_F(StackLinkedTest, LargeValues) {
    StackLinked s;
    s.push(1000000);
    s.push(2000000);
    EXPECT_EQ(s.pop(), 2000000);
    EXPECT_EQ(s.pop(), 1000000);
}

// Tests for QueueLinked
class QueueLinkedTest : public ::testing::Test {};

TEST_F(QueueLinkedTest, PutAndGet) {
    QueueLinked q;
    q.put(10);
    EXPECT_EQ(q.get(), 10);
}

TEST_F(QueueLinkedTest, FIFOOrder) {
    QueueLinked q;
    q.put(1);
    q.put(2);
    q.put(3);
    EXPECT_EQ(q.get(), 1);
    EXPECT_EQ(q.get(), 2);
    EXPECT_EQ(q.get(), 3);
}

TEST_F(QueueLinkedTest, MultiplePutGet) {
    QueueLinked q;
    q.put(5);
    q.put(10);
    EXPECT_EQ(q.get(), 5);
    q.put(15);
    EXPECT_EQ(q.get(), 10);
    EXPECT_EQ(q.get(), 15);
}

TEST_F(QueueLinkedTest, LargeSequence) {
    QueueLinked q;
    for(int i = 0; i < 100; i++) {
        q.put(i);
    }
    for(int i = 0; i < 100; i++) {
        EXPECT_EQ(q.get(), i);
    }
}

TEST_F(QueueLinkedTest, NegativeValues) {
    QueueLinked q;
    q.put(-1);
    q.put(-10);
    q.put(-100);
    EXPECT_EQ(q.get(), -1);
    EXPECT_EQ(q.get(), -10);
    EXPECT_EQ(q.get(), -100);
}

TEST_F(QueueLinkedTest, ZeroValues) {
    QueueLinked q;
    q.put(0);
    q.put(0);
    EXPECT_EQ(q.get(), 0);
    EXPECT_EQ(q.get(), 0);
}

TEST_F(QueueLinkedTest, MixedValues) {
    QueueLinked q;
    q.put(10);
    q.put(-5);
    q.put(0);
    EXPECT_EQ(q.get(), 10);
    EXPECT_EQ(q.get(), -5);
    EXPECT_EQ(q.get(), 0);
}

TEST_F(QueueLinkedTest, SingleElement) {
    QueueLinked q;
    q.put(42);
    EXPECT_EQ(q.get(), 42);
}

TEST_F(QueueLinkedTest, AlternatingPutGet) {
    QueueLinked q;
    for(int i = 0; i < 10; i++) {
        q.put(i);
        EXPECT_EQ(q.get(), i);
    }
}

TEST_F(QueueLinkedTest, LargeValues) {
    QueueLinked q;
    q.put(1000000);
    q.put(2000000);
    EXPECT_EQ(q.get(), 1000000);
    EXPECT_EQ(q.get(), 2000000);
}

TEST_F(QueueLinkedTest, EmptyAfterOperations) {
    QueueLinked q;
    q.put(1);
    q.put(2);
    q.get();
    q.get();
    EXPECT_TRUE(q.isEmpty());
}

TEST_F(QueueLinkedTest, NotEmptyAfterPut) {
    QueueLinked q;
    q.put(1);
    EXPECT_FALSE(q.isEmpty());
}

TEST_F(QueueLinkedTest, InterleavedOperations) {
    QueueLinked q;
    q.put(1);
    q.put(2);
    EXPECT_EQ(q.get(), 1);
    q.put(3);
    q.put(4);
    EXPECT_EQ(q.get(), 2);
    EXPECT_EQ(q.get(), 3);
    EXPECT_EQ(q.get(), 4);
}

TEST_F(QueueLinkedTest, TailUpdatesCorrectly) {
    QueueLinked q;
    q.put(1);
    q.put(2);
    q.put(3);
    // Getting all elements should set tail to NULL
    q.get();
    q.get();
    q.get();
    EXPECT_TRUE(q.isEmpty());
    // Should be able to add again
    q.put(4);
    EXPECT_EQ(q.get(), 4);
}

TEST_F(QueueLinkedTest, BatchOperations) {
    QueueLinked q;
    for(int i = 0; i < 5; i++) q.put(i);
    for(int i = 0; i < 5; i++) EXPECT_EQ(q.get(), i);
    for(int i = 5; i < 10; i++) q.put(i);
    for(int i = 5; i < 10; i++) EXPECT_EQ(q.get(), i);
}
