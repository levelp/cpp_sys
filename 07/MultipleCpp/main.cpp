#include <iostream>
#include <cstdio>

using namespace std;

#define S(x) cout << #x << " = " << x << endl;

// S(X+1)     #x -> "X+1"   x -> X+1

#include "module2.h"
#include "module2.h"
#include "module2.h"

//char hex2ascii(char* hex);


int main() {
  S(hex2ascii("41"));
  S(hex2ascii("4A"));
  for(char c = 32; c <= 'A'; c++)
    cout << c << " -> " << ascii2hex(c) << endl;

  return 0;
}
