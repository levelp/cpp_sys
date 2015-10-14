#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void solve_equation1(double a, double b, double c, double D);   //one x
void solve_equation2(double a, double b, double c, double D);   //two x
double inputA();
void message(int i);

const double EPS = 1e-10;
double a, b, c;
double D;
double x1;
double x2;

int main() {
  for(;;) {
    inputA();

    for (; a == 0; inputA())
      cout << "'a' can't be 0 :(" << endl;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;

    cout << endl;

    D = b * b - 4 * a * c;
    //cout << D << "\n\n" << endl;

    if((b == 0) && (c == 0))  message(1);

    if((D < 0) && (D < EPS))  message(2);

    if(D == 0)                solve_equation1(a, b, c, D);

    if((D > 0) && (D > EPS))  solve_equation2(a, b, c, D);

    cout << "\n\n" << endl;
  }

  return 0;
}

void solve_equation1(double a, double b, double c, double D) {
  x1 = (-b + sqrt(D)) / (2 * a);

  cout << "Result is " << x1 << "\n" << endl;

  system("pause");
}

void solve_equation2(double a, double b, double c, double D) {
  x1 = (-b + sqrt(D)) / (2 * a);
  x2 = (-b - sqrt(D)) / (2 * a);

  cout << "Result are x1 = " << x1 << " and x2 = " << x2 << "\n" << endl;

  system("pause");
}

double inputA() {
  cout << "a = ";
  cin >> a;
}

void message(int i) {
  switch(i) {
    case 1:
      cout << "Only one x and it's 0\n\n" << endl;
      system("pause");

    case 2:
      cout << "No x\n\n" << endl;
      system("pause");
  }
}
