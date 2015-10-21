/// Задание: работа с динамической памятью
/// --------------------------------------
#include <iostream>

using namespace std;

int main() {
  /// Вводим количество элементов в массиве
  /// (спрашиваем у пользователя)
  //-->
  int N;
  cout << "Enter number of elements: ";
  cin >> N;
  //<--

  /// Заводим массив в динамической памяти *new*
  /// int a; // Переменная 'a' целого типа
  /// int* a; // Указатель на переменную или массив
  ///    целого типа
  //-->
  int* A = new int[N];
  int* obj = new int;
  //<--

  /// Вводим в цикле элементы массива
  //-->
  for(int i = 0; i < N; i++) {
    cout << "A[" << i << "] = ";
    cin >> A[i];
  }
  //<--

  /// Ищем минимум и максимум в массиве
  /// и выводим их на экран
  //-->
  int min = A[0], max = A[0];
  for(int i = 1; i < N; i++) {
    if(A[i] < min) min = A[i];
    if(A[i] > max) max = A[i];
  }
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;
  //<--

  /// Очищаем динамическую память *delete*
  //-->
  delete[] A; // Со скобками [] т.к. new был со скобками
  delete obj;
  //<--

  return 0;
}
