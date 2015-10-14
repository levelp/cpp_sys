#include <iostream>
#include <string>

using namespace std;

struct Point {
  string name;
  double x, y;
  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }
  void show() {
    cout << name << ": " << x << " " << y << endl;
  }
  // Самая "маленькая" точка
  // - самая левая,
  // если таких несколько то самая верхняя
  bool operator <(Point& p) {
    if(x < p.x) return true;
    if(x > p.x) return false;
    // x == p.x
    return y < p.y;
  }
  Point operator -(Point& p) {
    // this - указатель на текущий объект
    // *this - содержимое текущего объекта
    Point res;
    res.x = x - p.x;
    res.y = y - p.y;
    res.name = name + " - " + p.name;
    return res;
  }
};

int main() {
  Point p = {"p", x: 2, y: 3};
  p.show();
  p.move(+1, 0);
  p.show();
  Point A = {"A", 3, 4};
  A.show();
  if(p < A)
    cout << "p < A" << endl;
  else if(A < p)
    cout << "p > A" << endl;
  else
    cout << "p == A" << endl;
  A = A - p;
  //A.operator-(p)
  A.show();
  return 0;
}
