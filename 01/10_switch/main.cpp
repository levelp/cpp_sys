// Множественный выбор switch
// ==========================
#include <iostream>

using namespace std;

int main() {
  //system("chcp(65001)");

  // Вводим количество углов
  //-->
  // N < 0 => ошибка
  // 0 углов => пустота
  // 1 угол => точка
  // 2 угла => отрезок
  // 3 угла => треугольник
  // 4 угла => четырёхугольник
  // N >= 5 углов => N-угольник
  int N;
  cout << "Enter number of edges: ";
  cin >> N;

  switch(N) {
    case 1: { // 1 угол => точка
      int i = 1, j = 10;

      //for(int k = 0; k < 10; ++k) {
      //}

      cout << "point" << endl; // Точка
    }
    break;

    case 0: // 0 углов => пустота или круг
      cout << "emptiness / circle" << endl;
      break;

    case 2: // 2 угла => отрезок
      cout << "segment" << endl;
      break;

    case 3: // 3 угла => треугольник
      cout << "triangle" << endl;
      break;

    case 4: // 4 угла => четырёхугольник
    case 5:
      // Общая обработка для случаев N = 4,5
      cout << N << "th polygon" << endl;
      break;

    //case -1:
    //  cout << "-1" << endl;

    //case -2:
    //  cout << "-2" << endl;

    // default вызывается когда не вызывается ни одна другая ветка
    default:  // N < 0 => ошибка, N >= 5 углов => N-угольник
      cout << ((N < 0) ? "error" : "N-edged polygon") << endl;
      break;

      //case -3:
      //  cout << "-3" << endl;
  }

  //<--
  return 0;
}
