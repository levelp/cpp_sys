# cpp_sys
C++ junior system programmer

Drivers USB to COM: http://www.prolific.com.tw/US/ShowProduct.aspx?p_id=225&pcid=41

## Test Suite

This repository now includes a comprehensive test suite with **218 unit tests** covering core components.

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

- ✅ **218 tests** across 11 test suites
- ✅ **100% pass rate**
- ✅ Coverage for: Queue, Stack, Rational, Square, Singleton, Factorial, Point, Array Utils, XOR Swap, hex2ascii

See `tests/README.md` for detailed documentation.

