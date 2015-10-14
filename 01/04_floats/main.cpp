// Пример на погрешность вычислений в вещественных числах
// Все вещественные типы: float / double / long double
//  представлены в памяти комьютера с погрешностью
#include <iostream>
#include <math.h>
#include <cfloat>

using namespace std;

// Точность сравнения - 0.000000001
const double EPS = 1e-9;
//  // DBL_EPSILON * 1000

int main() {
  float f = 0.023; // 4 байта

  long double ld = 0.12; // 10 байт

  double a = 0.1; // 8 байт
  double b = 0.9;
  double c = 1;

  // Неправильный способ:
  //if(a + b == c) {
  // Правильный способ:
  // fabs - взять по модулю
  if( fabs((a + b) - c) < EPS)
    cout << a << " + " << b << " == " << c << endl;
  else {
    cout << a << " + " << b << " != " << c << endl;
    cout << a + b << " " << c << endl;
    cout << c - (a + b) << endl;
  }

  return 0;
}
