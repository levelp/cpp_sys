#include <iostream>

#ifdef DEBUG
#include "hh.h"
#else
#include "hh.h"
#endif

#if defined(DEBUG) && defined(DEBUG1)

#endif // defined

#include "hh.h"

// Прототип (заголовок) функции
//void d_function();

using namespace std;

#warning My warning!

//#undef DEBUG

#ifndef DEBUG
#error DEBUG must be defined!
#endif // DEFINE

#if !defined(WIN32)
#error This program is only for Windows
#endif

int main() {
  d_function();
  return 0;
}
