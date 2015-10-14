// Нормальное использование if
// Минимум из двух чисел при помощи оператора if
#include <iostream>

using namespace std;

int main() {
  // Объявляю 2 переменные
  int a = 22, b = 10;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  if(a < b/*-1*/)
    cout << "min = a = " << a << endl;
  else
    cout << "min = b = " << b << endl;

  return 0;
}
