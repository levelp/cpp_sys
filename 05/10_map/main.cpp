#include <iostream>
#include <map>

using namespace std;

int main() {
  // Ассоциативный массив
  map<string, int> m;
  m["Один"] = 1;
  m["Два"] = 2;
  m["Три"] = 3;

  pair<string, int> x = *m.find("Два");
  cout << x.first << " " << x.second << endl;
  cout << m.find("Один")->second << endl;
  cout << m.find("Два")->second << endl;
  cout << m.find("Три")->second << endl;
  return 0;
}
