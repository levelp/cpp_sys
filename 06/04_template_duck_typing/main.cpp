// Утиная типизация - Duck Typing
// ------------------------------
#include <iostream>

using namespace std;

template <class T>
void duck_function(T t) {
  cout << "Before Krya" << endl;
  t.Krya(); // Метод "Кря"
  cout << "After Krya" << endl;
}

template <class T>
void dog_function(T t) {
  cout << "Before Gav" << endl;
  t.Gav(); // Метод "Гав"
  t.VilyaletHvostom(); // Виляет хвостом
  cout << "After Gav" << endl;
}

struct A {
  void Krya() {
    cout << "A: Krya!" << endl;
  }
};

struct B {
  void Gav() {
    cout << "B: Gav!" << endl;
  }
  void VilyaletHvostom() {
    cout << "B: VilyaletHvostom!" << endl;
  }
};

struct C {
  void Krya() {
    cout << "C: Krya!" << endl;
  }
  void Gav() {
    cout << "C: Gav!" << endl;
  }
  void VilyaletHvostom() {
    cout << "B: VilyaletHvostom!" << endl;
  }
};

int main() {
  A a;
  duck_function(a);
  B b;
  dog_function(b);
  //dog_function(a);

  C c;
  duck_function(c);
  dog_function(c);

  return 0;
}
