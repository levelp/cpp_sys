#include <iostream>

using namespace std;

// Плотная упаковка в памяти
#pragma pack(1)

struct Struct {
  char c; // 1 байт, но на 32 архитектуре выравнивание по 4 байта
  int i; // 4 байта
};

#define S(x) cout << #x << " = " << x << endl;

int main() {
  S(sizeof(Struct));

  return 0;
}
