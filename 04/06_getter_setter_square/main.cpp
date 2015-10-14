// Зачем нужны get/set методы?
// ---------------------------
// Don’t Repeat Yourself
// http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
#include <iostream>
#include <math.h>

#include "square.h"

/// Дублирование данных
//  |<-- сторона -->|
//  -----------------
//  |               |
//-->
class Square2 { // Квадрат
  // private - чтобы нельзя было "испортить" данные
  double side; // Сторона квадрата
  double area; // Площадь = сторона^2
 public:
  // Просто возвращаем значение
  double getSide() {
    return side;
  }
  double getArea() {
    return area;
  }
  // При изменении меняем одновременно (согласованно)
  void setSide(double value) {
    side = value;
    area = value * value;
  }
  void setArea(double value) {
    side = sqrt(value); // Квадратный корень / square root
    area = value;
  }
};
//<--

#define D(x) cout << #x << endl; x;
#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

int main() {
  Square s;
  D(s.setSide(12));
  SHOW(s.getSide());
  SHOW(s.getArea());

  D(s.setArea(100));
  SHOW(s.getSide());
  SHOW(s.getArea());

  return 0;
}
