#include <iostream>
#include <fstream>

using namespace std;

int main() {
  //
  ifstream in("in.txt");
  long long a, b;
  in >> a >> b;
  cout << "a = " << a << " b = " << b << endl;

  ofstream out("out.txt");
  out << "a = " << a << " b = " << b << endl;

  char buf[1000];
  in.getline(buf, 1000);
  cout << buf << endl;

  return 0;
}
