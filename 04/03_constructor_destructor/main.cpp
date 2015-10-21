/// Конструкторы и деструкторы
/// --------------------------
#include <iostream>

using namespace std;

//-->
// struct - С
// В С - тоже были структуры, но они не могли
// содержать методов
// class - С++
// Для объявления классов можно использовать слово
// struct
// при этом можно объявлять методы
// При этом уровень доступа public по-умолчанию для совместимости с C
struct Point {
  double x, y; // Поля
  // Добавляем в C++ метод: void move()
};

// Ключевое слово class
// Имя_класса
class MyClass {
  // Количество объектов
  static int count;
  // Идентификатор данного объекта
  int id;
  int* data;
  char* name;
 public:
  // Конструктор ИмяКласса()
  MyClass(char*);
  // Деструктор: ~ИмяКласса()
  ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

MyClass::MyClass(char* n = "no name") : name(n) {
  id = ++count;
  cout << "Constructor #" << id << " " << name << endl;
  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass() {
  cout << "Destructor #" << id << " " << name << endl;
  //cout << data << " " << data[0] << endl;
  delete[] data;
}

struct A {
  int w;
  A(int v) {
    w = v;
  }
};
//<--

int main() {
  {
    MyClass a("a"), b("b");
  }
  // В динамической памяти мы сами управляем созданием
  // и удалением объектов
  MyClass* aDyn = new MyClass("aDyn"),
  *bDyn = new MyClass("bDyn");
  delete aDyn;
  delete bDyn;

  /*A aa(10);
  A bb(aa);
  cout << bb.w << endl; */

  MyClass* p = new MyClass; // Конструктор
  delete p; // Деструктор

  cout << "MyClass d[2] >>>" << endl;
  {
    MyClass d[2];
  } // деструкторы для d
  cout << "<<<" << endl;
  cout << "MyClass e[2] >>>" << endl;
  {
    MyClass e[2];
  } // деструкторы для e
  cout << "<<<" << endl;
  /* MyClass f = a; */
  return 0;
}
