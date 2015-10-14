/// Переполнение строки символов
/// ----------------------------
/// Смертный Грех программиста №1 - источник уязвимостей
#include <iostream>
#include <cstring> // strcmp
//#include <iomanip> // setw

using namespace std;

int main() {
  // Строка для ввода пароля
  char password[8];
  // Корректный ли пароль?
  bool passwordCorrect = false; // 0 - false

  cout << "Enter your password: ";
  cin >> password;

  if(!strcmp(password, "123"))
    passwordCorrect = true;

  if(passwordCorrect)
    cout << "[OK] Password correct!" << endl;
  else
    cout << "(!) Wrong password! ACCESS DENIED!" << endl;

  return 0;
}
