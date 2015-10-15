// Задача на рекурсию "Скобочные последовательности"
// =================================================
// На входе: N - количество пар скобок
// Вывести все правильные скобочные
// последовательности из обычных скобок '(' ')'
// {} []
// из N пар скобок
// Например:
//  N = 1
// Ответ:
// ()
//  N = 2
// (())
// ()()
#include <iostream>

using namespace std;

int N; // Количество пар скобок

char s[100] = {0}; // Строчка со скобками

// Рекурсивная функция
// Уже поставлено:
//   o - открывающих  с - закрывающих
// Всего надо поставить N откр и N закр
void f(int o, int c) {
}

int main() {
  // Ввод данных
  cout << "N = ";
  cin >> N;
  f(0, 0); // Вызов рекурсии
  return 0;
}
