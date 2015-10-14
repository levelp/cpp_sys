#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Новая сложная структура данных
// Точка на плоскости
// Задаётся 2-мя координатами: x и y
struct Point2D {
  double x, y;

  // Операция сложения точек
  Point2D operator +(Point2D right) {
    Point2D res;
    res.x = x + right.x;
    res.y = y + right.y;
    return res;
  }
};

// Расстояние между 2-мя точками
double dist(Point2D A, Point2D B) {
  return sqrt( pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

using namespace std;

int main() {
  Point2D p1, p2 = {3.2, 4.3};
  p1.x = 10.0;
  p1.y = 2.3;
  cout << "p1: x = " << p1.x << " y = " << p1.y << endl;
  cout << "p2: x = " << p2.x << " y = " << p2.y << endl;
  p1 = p1 + p2; // Суммируем
  printf("p1: x = %f  y = %f\n", p1.x, p1.y);
  printf("p2: x = %f  y = %f\n", p2.x, p2.y);
  printf("dist(p1,p2) = %f\n", dist(p1, p2));
  return 0;
}
