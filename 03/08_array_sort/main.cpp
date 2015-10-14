/// Сортировка массива
/// ------------------
#include <iostream>
#include <algorithm> // sort Алгоритмы из STL

using namespace std;

/// Пример массива для сортировки
//-->
const int N = 6;
int A[N] = {1, 10, -2, 5, 6, 11};
//<--

// Выводим массив
void show() {
  for(int i = 0; i < N; ++i)
    cout << A[i] << " ";
  cout << endl;
}

int main() {
  show();
  // Задание: отсортировать массив
  // {-2, 10, 1, 5, 6, 11}
  // {-2, [ 1, 10, 5, 6, 11 ] }
  // {-2, 1, [5, 10, 6, 11 ] }
  bool changes;

  do {
    changes = false; // нет перестановок в массиве

    for(int i = 0; i < N - 1; ++i) {
      if(A[i] > A[i + 1]) {
        // SWAP
        //int temp = A[i];
        //A[i] = A[i+1];
        //A[i+1] = temp;
        //A[i] ^= A[i+1] ^= A[i] ^= A[i+1];
        cout << "swap(" << A[i] << ", " << A[i + 1] << ")" << endl;
        swap(A[i], A[i + 1]);
        show();
        changes = true;
      }
    }
    cout << "  changes " << changes << " -> ";
    show();
  } while(changes);

  for(int i = 0; i < N - 1; ++i)
    for(int j = i + 1; j < N; ++j)
      if(A[i] > A[j]) {
        cout << "swap(" << A[i] << ", " << A[j] << ")" << endl;
        swap(A[i], A[j]);
        show();
      }

  // -----
  // | 1 | 0
  // -----
  // | 3 | 1
  // -----
  // | 5 | 2
  // -----
  // | 6 | 3  <-- i
  // -----
  // | 7 | 4
  // -----

  // Снова вывести на экран
  show();

  return 0;
}
