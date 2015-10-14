#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
  // Печать целых чисел
  // %d - целое число
  // %3d - выравнивать по правому краю по 3 символа в столбце
  // %-3d - выравнивать по левому краю по 3 символа в столбце
  printf("%d\n", 10);
  for(int i = 1; i <= 6; i++) {
    for(int j = 1; j <= 6; j++)
      printf("%-3d", i * j);
    printf("\n");
  }
  // Дополнить спереди нулями
  printf("%08d\n", 234);
  // Шестнадцатеричная система счисления
  printf("%04x\n", 234); // строчными (маленькими)
  printf("%04X\n", 234); // прописными (большими)

  // Восьмеричная система счисления
  printf("%04o\n", 16 + 1); // 21

  printf("%u %d\n", 3000000000, 3000000000);

  // Действительные числа
  printf("PI = %f\n", M_PI); // 6 знаков
  printf("PI = %.3f\n", M_PI); // 3 знака
  printf("PI = %10.3f\n", M_PI);
  printf("PI = %-10.3f\n", M_PI);

  double d = 3123456789;
  printf("%f = %e = %E\n", d, d, d);
  printf("%g = %G\n", d, d);
  printf("%f %g\n", 3.10, 3.10);
  printf("%a = %A\n", d, d);

  char* str = "Test";
  printf("%c %c %s\n", str[0], '#', str);

  // Вывод очень больших чисел
  printf("%llu\n", 1123456789123456789LL);
  printf("%lld\n", 1123456789123456789LL);
  printf("%I64d\n", 1123456789123456789LL);

  return 0;
}
