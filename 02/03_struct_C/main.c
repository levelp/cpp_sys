#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Погрешность
const double EPS = 0.00000000001;

// Комплексное число - Complex number
//  3 + 2j
struct Complex {
  double re; // real - Действительная часть
  double im; // imagine - Мнимая часть
} zero = {0, 0}; // Сразу создаём константу "комплексный ноль"

// typedef  Описание_типа  Имя_нового_типа;
typedef struct Complex Comp;

// Вывод комплексного числа на экран
void show(Comp c) {
  if(fabs(c.im) < EPS)
    printf("%lf\n", c.re);
  else
    printf("%lf + %lf i\n", c.re, c.im);
}

Comp addComplex(Comp a, Comp b) {
  //Comp res = {a.re + b.re, a.im + b.im};
  Comp res;
  res.re = a.re + b.re;
  res.im = a.im + b.im;
  return res;
}

int main() {
  Comp a = {1, 0};
  show(a);
  // 1.000000
  Comp b = {2, 1};
  show(b);
  // 2.000000 + 1.000000 i
  Comp c = addComplex(a, b);
  show(c);
  // 3.000000 + 1.000000 i

  return 0;
}
