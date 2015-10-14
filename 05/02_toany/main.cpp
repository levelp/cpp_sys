#include <iostream>
#include <stdio.h>

using namespace std;

// Преобразование цифры в символ
// в какой-то системе счисления
char toChar(int digit) {
  // 0..9 => '0'..'9'
  if(digit <= 9)
    return '0' + digit;
  else // 10..35 => 'A'..'Z'
    return 'A' + (digit - 10);
}

// n - число для перевода
// base - основание системы счисления
string toAny(long long n, int base) {
  string res; // результат
  do {
    // Получаем очередную цифру числа
    char d = toChar(n % base);
    res = d + res;
    n /= base; // Делим (получаем частное)
  } while(n > 0);
  return res;
}

#ifdef DEBUG
#define S(x) cout << #x << " = " << x << endl;
#else
#define S(x)
#endif

int main() {
  S(toAny(7, 2));
  S(toAny(2004, 16));
  S(toAny(36, 35));
  S(toAny(0, 16));

  freopen("toany.in", "r", stdin);
#ifndef DEBUG
  freopen("toany.out", "w", stdout);
#endif // DEBUG
  while(!cin.eof()) {
    long long n;
    int base;
    cin >> n >> base;
    if(cin.good())
      cout << toAny(n, base) << endl;
  }

  return 0;
}
