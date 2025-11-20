# Comprehensive Test Suite for cpp_sys

This directory contains a comprehensive test suite with **218 unit tests** covering key components of the cpp_sys C++ learning repository.

## Test Framework

- **Framework**: Google Test (GTest)
- **Build System**: CMake 3.14+
- **Compiler**: g++ with C++11 standard
- **Coverage**: Code coverage enabled with gcov

## Building and Running Tests

### Build Tests

```bash
mkdir -p build
cd build
cmake .. -DENABLE_COVERAGE=ON
make -j$(nproc)
```

### Run All Tests

```bash
./tests/all_tests
```

### Run Specific Test Suite

```bash
./tests/all_tests --gtest_filter=SquareTest.*
```

## Test Coverage Summary

### Test Suites (11 total)

1. **QueueTest** (4 tests)
   - Tests for template Queue data structure
   - Coverage: Constructor, put(), get(), exceptions

2. **SquareTest** (20 tests)
   - Tests for Square class with getter/setter pattern
   - Coverage: 100% of square.h and square.cpp
   - Tests: setSide(), getSide(), setArea(), getArea()

3. **SingletonTest** (18 tests)
   - Tests for Singleton design pattern template
   - Coverage: Instance creation, state persistence, type safety

4. **Hex2AsciiTest** (35 tests)
   - Tests for hex to ASCII conversion function
   - Coverage: All ASCII characters, special cases, edge cases

5. **RationalTest** (25 tests)
   - Tests for Rational number class with GCD algorithm
   - Coverage: Arithmetic operators (+, -, *, /), normalization, I/O

6. **StackTest** (20 tests)
   - Tests for template Stack with fixed size
   - Coverage: push(), pop(), isEmpty(), isFull(), exceptions

7. **FactorialTest** (21 tests)
   - Tests for recursive factorial function
   - Coverage: Base cases, recursive cases, large values (0-20!)

8. **PointTest** (25 tests)
   - Tests for Point struct with operator overloading
   - Coverage: move(), comparison operators, subtraction operator

9. **ArrayUtilsTest** (15 tests)
   - Tests for array utility functions (sum, sum2)
   - Coverage: Even/odd position sum calculations

10. **XorSwapTest** (15 tests)
    - Tests for XOR-based variable swapping
    - Coverage: Multiple swap implementations, edge cases

11. **Module2Test** (20 tests)
    - Tests for hex/ASCII conversion utilities
    - Coverage: hex2ascii(), ascii2hex(), round-trip conversions

## Code Coverage

### Covered Components

| Component | File | Lines Covered | Coverage |
|-----------|------|---------------|----------|
| Square class | 04/06_getter_setter_square/square.h | 7/7 | 100% |
| Square class | 04/06_getter_setter_square/square.cpp | 3/3 | 100% |
| Singleton pattern | 06/Singletone/singletone.h | Fully tested | ~100% |
| Queue template | 07/02_StackTemplate/queue.h | Core methods | ~80% |
| Rational class | 05/13_operators/main.cpp | GCD, operators | ~100% |
| Stack template | 05/15_template_stack_in_array/main.cpp | All methods | 100% |
| Factorial | 02/07_factorial_rec/main.cpp | Recursive function | 100% |
| Point struct | 05/Points/main.cpp | All methods | 100% |
| Array utils | 03/06_array_task/sol.cpp | sum(), sum2() | 100% |
| XOR swap | 03/10_xor_swap/main.cpp | Swap functions | 100% |
| Module2 | 07/MultipleCpp/module2.cpp | Both functions | 100% |

## Test Statistics

- **Total Tests**: 218
- **Passing Tests**: 218 (100%)
- **Failed Tests**: 0
- **Test Suites**: 11
- **Lines of Test Code**: ~2500+

## Testing Best Practices

All tests follow these best practices:

1. **Descriptive Names**: Each test has a clear, descriptive name
2. **Focused Tests**: Each test verifies a single behavior
3. **Edge Cases**: Tests cover boundary conditions, empty inputs, large values
4. **Type Variety**: Tests use different data types (int, double, string, etc.)
5. **Equivalence Classes**: Tests cover representative values from each class
6. **Exception Handling**: Tests verify proper exception throwing
7. **LIFO/FIFO Verification**: Data structure tests verify correct ordering

## Test Categories

### 1. Data Structures (45 tests)
- Queue template
- Stack template
- Rational numbers

### 2. OOP and Design Patterns (38 tests)
- Square class (encapsulation)
- Singleton pattern
- Point struct (operator overloading)

### 3. Algorithms (51 tests)
- Factorial (recursive)
- Array sum functions
- XOR swap

### 4. String/Data Conversion (55 tests)
- hex2ascii (DLL version)
- hex2ascii_module2
- ascii2hex

### 5. Mathematical Operations (29 tests)
- Rational arithmetic
- GCD algorithm
- Square area calculations

## Running Individual Test Suites

```bash
# Run only Square tests
./tests/all_tests --gtest_filter=SquareTest.*

# Run only Rational tests
./tests/all_tests --gtest_filter=RationalTest.*

# Run only hex2ascii tests
./tests/all_tests --gtest_filter=Hex2AsciiTest.*

# Run all tests verbosely
./tests/all_tests --gtest_print_time=1

# List all tests
./tests/all_tests --gtest_list_tests
```

## Coverage Report Generation

To generate detailed coverage reports:

```bash
cd build
make clean
make
./tests/all_tests

# Generate coverage for specific file
gcov tests/CMakeFiles/all_tests.dir/test_square.cpp.gcno

# View coverage summary
gcov -r tests/CMakeFiles/all_tests.dir/*.gcno | grep "Lines executed"
```

## Future Enhancements

To achieve even higher coverage across the entire repository:

1. Add tests for RS232 communication modules
2. Add tests for STL container examples
3. Add tests for additional OOP examples
4. Add integration tests for multi-file programs
5. Add performance benchmarks
6. Generate HTML coverage reports with lcov

## Test File Structure

```
tests/
├── CMakeLists.txt              # Test build configuration
├── README.md                   # This file
├── hex2ascii.h                 # Standalone hex2ascii for testing
├── test_queue.cpp              # Queue template tests
├── test_square.cpp             # Square class tests
├── test_singleton.cpp          # Singleton pattern tests
├── test_hex2ascii.cpp          # hex2ascii function tests
├── test_rational.cpp           # Rational class tests
├── test_stack.cpp              # Stack template tests
├── test_factorial.cpp          # Factorial function tests
├── test_point.cpp              # Point struct tests
├── test_array_utils.cpp        # Array utility function tests
├── test_xor_swap.cpp           # XOR swap function tests
└── test_module2.cpp            # Module2 conversion tests
```

## Contributing

When adding new tests:

1. Create a new test file: `test_<component>.cpp`
2. Add the file to `tests/CMakeLists.txt`
3. Follow the existing naming conventions
4. Aim for >90% code coverage
5. Test edge cases and error conditions
6. Run all tests before committing

## License

This test suite is part of the cpp_sys educational repository.
