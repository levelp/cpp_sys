// Задача
// Ввести из файла in.txt количество строк N
// Ввести из файла N строк
// Отсортировать их и вывести в файл
// out.txt
#include <iostream>
#include <fstream>
#include <algorithm> // sort
#include <vector> // vector
#include <string> // string

using namespace std;

int main() {
  // Вектор для хранения строк
  vector<string> strings;
  // Открываем входной файл
  ifstream in("in.txt");

  // Считываем сами строки
  // in.eof() in.good() - до конца файла
  while(!in.eof()) {
    string s;
    getline(in, s); // getline(поток, куда_поместить_результат)
    //in >> s;
    if(!in.good())
      break;
    strings.push_back(s);
    cout << s << endl;
  }

  //if(string("test") < string("sdfdsf")){
  //
  //}

  // Сортируем
  sort(strings.begin(), strings.end());

  int A[10];
  sort(A, A + 10);

  // Открываем файл для вывода
  ofstream out("out.txt");

  // Выводим строки
  /*for(int i = 0; i < strings.size(); ++i)
    out << strings[i] << endl; */

  for(vector<string>::iterator
      i = strings.begin();
      i != strings.end();
      ++i )
    out << *i << endl;

  // Закрываем файл
  out.close();
  return 0;
}
