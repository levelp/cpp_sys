<!-- doc.py -->
Наследование: поле с тем же имененем
------------------------------------
Пусть есть класс **A**
с полем **x** и методом **show**
``` cpp
struct A {
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};
```

И его наследник **B**
тоже с полем **x** и методом **show**
``` cpp
struct B : public A {
  int x = -2;
  void show() {
    cout << "x = " << x << endl;
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};
```

Как получить доступ к каждому из полей **x**?
``` cpp
int main() {
  A a;
  B b;
  //a.x = 1;
  a.show();
  //b.x = 2;
  b.A::show();
  b.B::show();
  //b.show();
  return 0;
}
```

[main.cpp](main.cpp)

