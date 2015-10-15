#include <iostream>

using namespace std;

// По значению - by value - копируется значение
// Внутри функции возникает новая переменная i, при изменении которой
// "основная" i никак не меняется
void f1(int  i) {
  i++;
  cout << "i = " << i << endl;
}
// По ссылке - by reference
// i внутри функции - новое имя (алиас, alias) для внешней переменной
void f2(int& i) {
  i++;
  cout << "i = " << i << endl;
}
// По указателю - by pointer
void f3(int* i) {
  (*i)++;
  cout << "i = " << *i << endl;
}

int main() { // Основная программа
  int i = 3; // "Основная" переменная i
  // Сначала она равна 3
  f1(i);
  cout << "i = " << i << endl; // i = 3 по-прежнему
  f2(i);
  cout << "i = " << i << endl; // i увеличилась
  f3(&i);
  cout << "i = " << i << endl; // i ещё раз увеличилась
  return 0;
}
