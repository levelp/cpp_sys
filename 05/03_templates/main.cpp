#include <iostream>
#include <string>

#define S(x) cout << #x << " = " << x << endl;

using namespace std;

/*int min(int a, int b) {
  cout << "int min(int a, int b)" << endl;
  return (a < b) ? a : b;
}

double min(double a, double b) {
  cout << "double min(double a, double b)" << endl;
  return (a < b) ? a : b;
}

string min(string a, string b) {
  cout << "string min(string a, string b)" << endl;
  return (a < b) ? a : b;
} */

//template <class X>
template <typename X> // class, typename
X min(X a, X b) {
  return (a < b) ? a : b;
}

template <class T, typename Q, int size>
T min(T a, Q b) {
  return (a < b) ? a : b;
}


int main() {
  S(::min<double>(2, 3));
  S(::min(2.2, 3.1));
  S(::min("test", "hi"));
  return 0;
}
