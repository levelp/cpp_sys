// Модулю 2

#include <stdio.h>

#include "module2.h"

using namespace std;

// На выходе - ASCII символ
// На входе 2
char hex2ascii(char* hex) {
  int code;
  sscanf(hex, "%X", &code);
  return (char)code;
}

string ascii2hex(char c) {
  char str[3]; // <-- сюда будем печатать
  sprintf(str, "%02X", (int)c);
  return string(str);
}


