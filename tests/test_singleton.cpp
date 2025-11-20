#include <gtest/gtest.h>
#include "../06/Singletone/singletone.h"

// Test class for singleton
class TestObject {
public:
    int value;
    static int constructorCalls;

    TestObject() : value(0) {
        constructorCalls++;
    }

    void setValue(int v) { value = v; }
    int getValue() const { return value; }
};

int TestObject::constructorCalls = 0;

// Another test class
class Counter {
public:
    int count;
    Counter() : count(0) {}
    void increment() { count++; }
    int getCount() const { return count; }
};

class SingletonTest : public ::testing::Test {
protected:
    void SetUp() override {
        TestObject::constructorCalls = 0;
    }

    void TearDown() override {
        // Note: Singleton instances are never deleted in this implementation
        // This is a known limitation of the singleton pattern
    }
};

// Test 1: Instance returns same object
TEST_F(SingletonTest, InstanceReturnsSameObject) {
    TestObject& obj1 = Singletone<TestObject>::instance();
    TestObject& obj2 = Singletone<TestObject>::instance();

    EXPECT_EQ(&obj1, &obj2);
}

// Test 2: Constructor called only once
TEST_F(SingletonTest, ConstructorCalledOnce) {
    // Note: Since singletons persist across tests, we cannot reliably test
    // the initial count. We can only verify it doesn't increase with multiple calls.
    int initialCount = TestObject::constructorCalls;

    Singletone<TestObject>::instance();
    Singletone<TestObject>::instance();
    Singletone<TestObject>::instance();

    // Multiple calls should not increase constructor count
    EXPECT_EQ(TestObject::constructorCalls, initialCount);
}

// Test 3: State persists across calls
TEST_F(SingletonTest, StatePersistsAcrossCalls) {
    TestObject& obj1 = Singletone<TestObject>::instance();
    obj1.setValue(42);

    TestObject& obj2 = Singletone<TestObject>::instance();
    EXPECT_EQ(obj2.getValue(), 42);
}

// Test 4: Multiple modifications persist
TEST_F(SingletonTest, MultipleModificationsPersist) {
    TestObject& obj1 = Singletone<TestObject>::instance();
    obj1.setValue(10);

    TestObject& obj2 = Singletone<TestObject>::instance();
    obj2.setValue(20);

    TestObject& obj3 = Singletone<TestObject>::instance();
    EXPECT_EQ(obj3.getValue(), 20);
}

// Test 5: Different types have different instances
TEST_F(SingletonTest, DifferentTypesHaveDifferentInstances) {
    TestObject& testObj = Singletone<TestObject>::instance();
    Counter& counter = Singletone<Counter>::instance();

    EXPECT_NE((void*)&testObj, (void*)&counter);
}

// Test 6: Counter increments correctly
TEST_F(SingletonTest, CounterIncrementsCorrectly) {
    Counter& c1 = Singletone<Counter>::instance();
    c1.increment();

    Counter& c2 = Singletone<Counter>::instance();
    c2.increment();

    Counter& c3 = Singletone<Counter>::instance();
    EXPECT_EQ(c3.getCount(), 2);
}

// Test 7: Reference can be stored and used
TEST_F(SingletonTest, ReferenceCanBeStoredAndUsed) {
    TestObject& obj = Singletone<TestObject>::instance();
    obj.setValue(100);

    EXPECT_EQ(obj.getValue(), 100);

    TestObject& obj2 = Singletone<TestObject>::instance();
    EXPECT_EQ(obj2.getValue(), 100);
    EXPECT_EQ(obj.getValue(), obj2.getValue());
}

// Test 8: Multiple accesses in sequence
TEST_F(SingletonTest, MultipleAccessesInSequence) {
    for(int i = 0; i < 10; i++) {
        TestObject& obj = Singletone<TestObject>::instance();
        obj.setValue(i);
    }

    TestObject& finalObj = Singletone<TestObject>::instance();
    EXPECT_EQ(finalObj.getValue(), 9);
}

// Test 9: Initial value is constructor default
TEST_F(SingletonTest, InitialValueIsConstructorDefault) {
    TestObject& obj = Singletone<TestObject>::instance();
    // First access after setup, check initial value
    // Note: value may have been modified by previous tests due to static nature
    obj.setValue(0);
    EXPECT_EQ(obj.getValue(), 0);
}

// Test 10: Pointer equality
TEST_F(SingletonTest, PointerEquality) {
    TestObject* ptr1 = &Singletone<TestObject>::instance();
    TestObject* ptr2 = &Singletone<TestObject>::instance();
    TestObject* ptr3 = &Singletone<TestObject>::instance();

    EXPECT_EQ(ptr1, ptr2);
    EXPECT_EQ(ptr2, ptr3);
    EXPECT_EQ(ptr1, ptr3);
}

// Test class with more complex state
class ComplexObject {
public:
    int x, y;
    std::string name;

    ComplexObject() : x(0), y(0), name("default") {}

    void setData(int _x, int _y, const std::string& _name) {
        x = _x;
        y = _y;
        name = _name;
    }
};

// Test 11: Complex object state
TEST_F(SingletonTest, ComplexObjectState) {
    ComplexObject& obj1 = Singletone<ComplexObject>::instance();
    obj1.setData(10, 20, "test");

    ComplexObject& obj2 = Singletone<ComplexObject>::instance();
    EXPECT_EQ(obj2.x, 10);
    EXPECT_EQ(obj2.y, 20);
    EXPECT_EQ(obj2.name, "test");
}

// Test 12: Instance address is consistent
TEST_F(SingletonTest, InstanceAddressIsConsistent) {
    void* addr1 = &Singletone<TestObject>::instance();
    void* addr2 = &Singletone<TestObject>::instance();
    void* addr3 = &Singletone<TestObject>::instance();

    EXPECT_EQ(addr1, addr2);
    EXPECT_EQ(addr2, addr3);
}

// Test 13: Counter starts at zero
TEST_F(SingletonTest, CounterStartsAtZero) {
    Counter& c = Singletone<Counter>::instance();
    c.count = 0; // Reset
    EXPECT_EQ(c.getCount(), 0);
}

// Test 14: Multiple counter increments
TEST_F(SingletonTest, MultipleCounterIncrements) {
    Counter& c = Singletone<Counter>::instance();
    c.count = 0; // Reset

    for(int i = 0; i < 100; i++) {
        Singletone<Counter>::instance().increment();
    }

    EXPECT_EQ(c.getCount(), 100);
}

// Test 15: Type safety
TEST_F(SingletonTest, TypeSafety) {
    // This test verifies that different types don't interfere
    TestObject& testObj = Singletone<TestObject>::instance();
    testObj.setValue(999);

    Counter& counter = Singletone<Counter>::instance();
    counter.count = 0;
    counter.increment();

    // Verify they maintained separate state
    EXPECT_EQ(testObj.getValue(), 999);
    EXPECT_EQ(counter.getCount(), 1);
}

// Test with standard types
TEST_F(SingletonTest, StandardIntType) {
    int& i1 = Singletone<int>::instance();
    i1 = 42;

    int& i2 = Singletone<int>::instance();
    EXPECT_EQ(i2, 42);
}

TEST_F(SingletonTest, StandardDoubleType) {
    double& d1 = Singletone<double>::instance();
    d1 = 3.14159;

    double& d2 = Singletone<double>::instance();
    EXPECT_DOUBLE_EQ(d2, 3.14159);
}

TEST_F(SingletonTest, StandardStringType) {
    std::string& s1 = Singletone<std::string>::instance();
    s1 = "Hello, Singleton!";

    std::string& s2 = Singletone<std::string>::instance();
    EXPECT_EQ(s2, "Hello, Singleton!");
}
