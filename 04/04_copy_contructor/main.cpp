// Конструктор копирования
// -----------------------
#include <iostream>
#include <string.h>

using namespace std;

//-->
// Класс "строка"
class String {
  static int count; // Количество строк
  char* s; // Сама строка
 public:
  int id; // Идентификатор данной строки
  // Конструктор
  String(char* str) : id(++count), s(str) {
    cout << "Constructor #" << id << " \"" << str << "\"" << endl;
    s = new char[strlen(str) + 1]; // +1 потому что строка заканчивается
    // символом \0
    //   куда <- откуда
    strcpy(s, str);
  };
  // Конструктор копирования
  String(String& r) : String(r.s) {
  }
  // Вывод строки на экран
  void show() {
    cout << s << endl;
  }
  // Деструктор
  ~String() {
    cout << "Destructor #" << id << endl;
    delete[] s; // Очищаем динамическую память
  }
};

// Сначала количество строчек равно 0
int String::count = 0;
//<--

int main() {
  char s[] = "Test";
  cout << s << endl;
  // Адрес текста в памяти
  int i = (int)s;
  cout << i << endl;

  String s1(s);
  s1.show();
  String s2(s);
  s2.show();
  s[0] = '#';
  cout << s << endl;
  s1.show();
  s2.show();

  String s3 = s1; // Вызов конструктора копирования
  // String s3(s1); // Тоже вызов конструктора копирования
  s3.show();

  return 0;
}
