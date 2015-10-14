#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cmath>


const double EPS = 1e-10;

double delta_count(double na, double nb, double nc) {
  double delta = nb * nb - 4 * na * nc;

  if (fabs(delta) < EPS)
    delta = 0;

  return delta;
}

double two_sol(double na, double nb, double ndelta) {
  double x1, x2;

  if (ndelta > 0) {
    x1 = (-nb - sqrt(ndelta)) / (2 * na);

    if (fabs(x1) < EPS)
      x1 = 0;

    x2 = (-nb + sqrt(ndelta)) / (2 * na);

    if (fabs(x2) < EPS)
      x2 = 0;

    std::cout << "x1=" << x1 << "\n" << "x2=" << x2 << "\n\n";

  } else {
    x1 = -nb / (2 * na);
    std::cout << "x1=" << x1 << "\n";
  }

  return 0;

}
int main() {
start:
  double a, b, c, delta, x1;
  std::cout << " a: ";
  std::cin >> a;
  //if (a==0)
  //{
  //std::cout << "Factor a can't be equal 0\n\n ";
  //goto start;
  //}
  std::cout << " b: ";
  std::cin >> b;
  std::cout << " c: ";
  std::cin >> c;

  if (a == 0 && b == 0 && c == 0)
    std::cout << "Infinitely many solutions" << "\n\n";
  else if  (a == 0 && b == 0 && c != 0)
    std::cout << "Inconsistency" << "\n\n";
  else if (a == 0 && b != 0) {
    std::cout << "Linear equation with 1 solution:" << "\n\n";
    x1 = c / (-b) ;

    if (fabs(x1) < EPS)
      x1 = 0;

    std::cout << "x1=" << x1 << "\n";
  } else {
    //std::cout << "Rownanie kwadratowe :" << a << "x2" << "+" << b << "x" << "+" << c<< "= 0\n\n";
    delta = delta_count(a, b, c);
    std::cout << "\n Delta:" << delta << "\n\n";

    if (delta > 0) {
      std::cout << "Two solution: \n\n";
      two_sol(a, b, delta);

    } else if (delta == 0) {
      std::cout << "One solution: \n ";
      two_sol(a, b, delta);

    } else
      std::cout << "Delta less than zero. No solution \n ";

    system("pause");
    std::cout << std::endl << std::endl;
    goto start;

    return 0;
  }
}
