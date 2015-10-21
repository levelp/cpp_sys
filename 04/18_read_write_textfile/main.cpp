#include <iostream>
#include <cstdio> // c + stdio
// #include <stdio.h>

using namespace std;

int main() {
  // Ввод из файла вместо клавиатуры
  freopen("input.txt", "r", stdin);
  // Вывод в файл вместо экрана
  // имя_файла
  // "w" - запись / write
  freopen("result.txt", "w", stdout);
  int N;
  cin >> N;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << "sum = " << sum << endl;

  return 0;
}
