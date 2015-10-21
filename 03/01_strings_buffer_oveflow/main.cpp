/// Переполнение строки символов
/// ----------------------------
/// Смертный Грех программиста №1 - источник уязвимостей
#include <iostream>
#include <cstring> // strcmp
#include <iomanip> // setw

using namespace std;

// Два способа ограничить ввод:
// Использовать string вместо char[SIZE]
//#define STRING
// Использовать setw(SIZE) при вводе
//#define SETW

int main() {
  // Строка для ввода пароля
#ifdef STRING
  string password;
#else
  char password[8];
#endif
  // Корректный ли пароль?
  bool passwordCorrect = false; // 0 - false

  cout << "Enter your password: ";
  // Ограничиваем количество вводимых символов
#ifdef SETW
  cin >> setw(8) >> password;
#else
  cin >> password;
#endif // SETW

  // Ввод с клавиатуры
  // Ввод из файла
  // Получение пакета из сети
#ifdef STRING
  if(password == "123")
    passwordCorrect = true;
#else
  if(!strcmp(password, "123"))
    passwordCorrect = true;
#endif

  if(passwordCorrect)
    cout << "[OK] Password correct!" << endl;
  else
    cout << "(!) Wrong password! ACCESS DENIED!" << endl;

  return 0;
}
