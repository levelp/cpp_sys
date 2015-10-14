#include <iostream>
#include <string>
#include <vector> // vector

using namespace std;

int main() {
  //string vv[4];
  vector<string> v(2, "!");
  // Добавляем в конец вектора
  v.push_back("s1");
  v.push_back("s2");
  v.push_back("s3");
  v.push_back("s4");

  // v.size() - размер (текущее количество элементов)
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl; // индексация как в массиве

  v.erase(v.begin() + 2);

  cout << endl;
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;

  // Уменьшение размера => все "лишние" элементы будут удалены
  v.resize(3);

  cout << endl;
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;

  v.resize(8, "Test");
  v.insert(v.begin(), "to begin");
  for(int i = 0; i < v.size(); ++i)
    cout << v[i] << endl;
  v.insert(v.begin() + 1, "after first");
  v.insert(v.end() - 1, "before last");
  v.insert(v.begin() + v.size() / 2, "to center");

  //for(vector<string>::iterator i = v.begin(); i != v.end(); i++){
  //  cout << *i << endl;
  //}
  // C++11
  auto a = 2.2;
  for(auto i = v.begin(); i != v.end(); i++)
    cout << *i << endl;

  vector<vector<int> > x;
  x.resize(100);
  x[0].resize(100);

  return 0;
}
