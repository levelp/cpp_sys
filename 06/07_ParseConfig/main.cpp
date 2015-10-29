#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define S(x) cout << #x << " = " << x << endl;

int n;
int WiFi;
string FileName;
string TV;
vector<int> A;

int main() {
  // ifstream - input file stream
  ifstream in("config.ini");
  while(!in.eof()) {
    string name; // Имя параметра
    string value; // Значение
    in >> name;
    if(name == "#") {
      getline(in, value);
      continue;
    }
    S(name);
    string op; // Операция
    in >> op;
    if(op != "=") {
      getline(in, value);
      continue;
    }
    // value =
#define PARAM(x) if(name == #x){ in >> x; }
    PARAM(n);
    PARAM(WiFi);
    PARAM(FileName);
    PARAM(TV);
    if(name == "A") {
      getline(in, value);
      S(value);
      // Читаем из строчки как из файла
      istringstream is(value);
      do {
        int x;
        is >> x; // Читаем целое число
        if(is.good())
          A.push_back(x);
      } while(is.good());
      cout << "A: ";
      // auto - автоматический вывод типа
      // из C++ 11
      for(auto i = A.begin(); i != A.end(); i++)
        cout << *i << " ";
      cout << endl;
    }
  }
  S(n);
  S(WiFi);
  S(FileName);
  S(TV);
  return 0;
}
