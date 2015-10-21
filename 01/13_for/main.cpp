#include <iostream>
//#include <stdio.h> // C
#include <cstdio> // C++
#include <iomanip> // setw()

using namespace std;

int main() {
  const int MAX = 10;

  // for(присв_начального_значения; условие_прод; щаг){
  for(int i = 1; i <= MAX; ++i) {
    for(int j = 1; j <= MAX; ++j){
      //   %d - печать целого числа
      //   %4d - печать целого числа,
      //  на каждое число по 4 символа
      printf("%4d", (i * j));
      //cout << setw(4) << (i*j);
    }

    printf("\n"); // Переход на следующую строчку
    //cout << endl;
  }
  return 0;

  for(int i = 0, j = 10;
      i < 100 && j < 30;
      i += 5, j += 7, ++i, i += 3)
    cout << "i = " << i << "  j = " << j << endl;

  // Перевод строки на различных платформах:
  //  Windows: CR LF - 13 10  printf("\r\n")
  //  *nix (Linux...): LF - 10  printf("\n")
  //  MacOS (до MacOSX): CR - 13  printf("\r")

  return 0;
}
