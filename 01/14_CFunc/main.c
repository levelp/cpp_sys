// Объявление и вызов функций
#include <stdio.h>
#include <stdlib.h>

// abs()  fabs()
//  имя(аргументы)
int min(int a, int b) {
  if(a < b)
    return a;
  else
    return b;
}

double fmin(double a, double b) {
  if(a < b)
    return a;
  else
    return b;
}

// fabs, abs

int main() {
  printf("min(2, 5) = %d\n", min(2, 5));
  return 0;
}
