// Условный оператор if
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  // Переменная i меняется от -3 до 3 в цикле
  // i = -3 -2 -1 0 1 2 3
  for(int i = -3; i <= 3; ++i)
    if(i)
      cout << i << " - TRUE" << endl;
    else
      cout << i << " - FALSE" << endl;

  int a = 2, b = 3;

  // && - логическое И
  // || - логическое ИЛИ
  // ! - логическое НЕ
  if(a != 2)
    cout << "Верно!" << endl;
  else
    cout << "Неверно!" << endl;

  a + b;

  // Тернарный оператор - альтернатива if
  int min = (a < b) ? a : b;

  return 0;
}
