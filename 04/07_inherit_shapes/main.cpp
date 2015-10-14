/// Наследование
/// ------------
#include <iostream>

using namespace std;

/// Общий предок - фигура
//-->
struct Shape {
  char name[100]; // У всех фигур есть имя
  int color; // Цвет фигуры
  void method() {
    cout << "method" << endl;
  }
};
//<--

// Отношение наследование - от общего к частному

// Точка - наследник класса Фигура
class Point : public Shape {
 public:
  double x, y;
};

class Circle : public Shape {
 public:
  Point center; // Центр
  double radius; // Радиус
};

class Square : public Shape {
 public:
  Point p1, p2, p3, p4;
};

class SquareWithBorder : public Square {
  // Унаследовано всё от Shape
  // всё от Square
  // + свои свойства
  int borderWidth = 1;
  int borderColor = 10;
};

int main() {
  Shape shape;
  Square square;
  Circle circle;
  circle.name = "Окружность";
  Point point;
  point.name = "Точка 1";
  return 0;
}
