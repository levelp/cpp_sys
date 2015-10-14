#include <iostream>
#include <set> // Множества (исключает повторяющиеся элементы)

using namespace std;

#define S(x) cout << #x << " = " << x << endl;

int main() {
  set<int> s;
  s.insert(2);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  S(s.size());
  for(auto i = s.begin(); i != s.end(); i++)
    S(*i);

  if(s.find(33) == s.end())
    cout << "Not found!" << endl;
  else
    cout << "Found!" << endl;

  s.erase(2);
  for(auto i = s.begin(); i != s.end(); i++)
    S(*i);

  return 0;
}
