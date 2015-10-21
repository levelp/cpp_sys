#include <iostream>
#include <math.h>

using namespace std;

// Точка
struct Point {
  double x, y;
};

typedef Point Vector;

double sqr(double x) {
  return x * x;
}

double dist(Point a, Point b) {
  return
    sqrt(sqr(a.x - b.x) +
         sqr(a.y - b.y));
}

// Сумма
Point sum(Vector A, Vector B) {
  // TODO: Реализовать
  return R;
}

// Разность
Point sub(Vector A, Vector B) {
  // TODO: Реализовать
  return R;
}

// Скалярное произведение векторов
double dotProduct(Vector A, Vector B) {
  // TODO: Реализовать
}

int main() {
  Point a = {1.2, 1.3},
        b = {10.2, 3.3};
  cout << dist(a, b) << endl;

  // Тестирование
  Point c1 = sum(a, b);
  Point c2 = sub(a, b);
  double p = dotProduct(a, b);

  return 0;
}
