# cpp_sys
C++ junior system programmer

Drivers USB to COM: http://www.prolific.com.tw/US/ShowProduct.aspx?p_id=225&pcid=41

## Test Suite

This repository now includes a comprehensive test suite with **290 unit tests** covering core components.

### Quick Start

```bash
# Build tests
mkdir -p build && cd build
cmake .. -DENABLE_COVERAGE=ON
make -j$(nproc)

# Run all tests
./tests/all_tests
```

### Test Coverage

- ✅ **290 tests** across 15 test suites
- ✅ **100% pass rate**
- ✅ Coverage for: Queue (template & array & linked list), Stack (template & linked list), Rational, Square, Singleton, Factorial, Point, Array Utils, XOR Swap, hex2ascii, Template Sum with Complex numbers

See `tests/README.md` for detailed documentation.

