#include <iostream>
#include <windows.h>

using namespace std;

#define MY_CONST  123456
#define SQR(x)  (x)*(x)
#define MIN(x,y) ((x < y) ? (x) : (y))
#define SHOW_LINE  cout << __FILE__ << ":" << __LINE__ << endl;
#define WHERE_AM_I cout << __FUNCTION__ << ":" \
                        << __LINE__ << endl;
#define forn(i, s, n) for(int i = s; i < (int)n; ++i)
#define fill(a, x) memset(a, x, sizeof(a));
void f() {
  WHERE_AM_I;
}

int main() {
#define X1

#ifdef X1
  WHERE_AM_I;
#endif
#undef X1

#ifdef X1
  cout << MY_CONST << endl;
#endif
  cout << SQR(SQR(5)) << endl;
#ifdef LINUX
  SHOW_LINE;
#endif
  cout << MIN(23, 32) << endl;
  SHOW_LINE;
  cout << __FUNCTION__ << endl;
  f();
  forn(i, 0, 10)
  forn(j, 0, 10)

  int A[10];
  fill(A, 0);
  fill(A, 1);

  return 0;
}
