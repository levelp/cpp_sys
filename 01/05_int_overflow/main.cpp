#include <iostream>

using namespace std;

//              Название переменной = Значение
#define SHOW(x) cout << #x << " = " << x << endl;

int main() {
  long long l; // 64-битная переменная
  //   2^32-1 + 1 = 2^32
  l = 4294967295U + 1;
  //   11111111 11111111 11111111 11111111
  // +                                   1
  // 1 00000000 00000000 00000000 00000000
  //  4294967296
  SHOW(l)

  long long l2;
  l2 = 4294967295LL + 1;
  SHOW(l2)

  long long l3 = 4294967295U;
  l3 = l3 + 1;
  SHOW(l3)

  SHOW(1 + 2 - 3 * 2)

  return 0;
}
