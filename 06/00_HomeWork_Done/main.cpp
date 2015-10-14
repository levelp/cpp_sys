#include <iostream>
#include <assert.h>

using namespace std;

typedef long long ll;

// НОД - Наибольший общий делитель
// https://ru.wikipedia.org/wiki/Наибольший_общий_делитель
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}

// Рациональная дробь: p/q
class Rational {
  ll p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    ll d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
 public:
  // Конструктор
  Rational(ll p, ll q) : p(p), q(q) {
    normalize();
  };
  // Ввод с клавиатуры
  Rational(const char* message) {
  }
  // Показать дробь на экран (в консоль)
  void show() {
    normalize();
    if(p > q) {
      cout << p / q << " ";
      p %= q;
    }
    cout << p << "/" << q << endl;
  };
  // Сложение дробей
  // a + b
  Rational operator+(Rational& r) {
    // this - указатель на текущий объект
    // *this - текущий объект
    //   p     r.p     p * r.q + r.p * q
    //  --- + ----- = -------------------
    //   q     r.q          q * r.q
    return Rational( p * r.q + r.p * q,
                     // ---------------
                     q * r.q
                   );
  }


  // прибавить к дроби целое число
  Rational operator+(int r) {
    return Rational( p + r * q,
                     // -----------
                     q
                   );
  }

  // Прибавить к целому число дробь
  friend Rational
  operator+(long left, Rational& r) {
    return Rational( left * r.q + r.p,
                     // -----------------
                     r.q
                   );
  }

  // Вычитание
  Rational operator-(Rational& r) {
    //   p     r.p     p * r.q - r.p * q
    //  --- - ----- = -------------------
    //   q     r.q          q * r.q
    return Rational( p * r.q - r.p * q,
                     // ---------------
                     q * r.q                    );

  }

  Rational operator*(Rational& r) {
    //   p     r.p     p * r.p
    //  --- * ----- = ---------
    //   q     r.q     q * r.q
    return Rational( p * r.p,
                     // ---------
                     q * r.q
                   );
  }

  Rational operator/(Rational& r) {
    //   p     r.p     p * r.q
    //  --- / ----- = ---------
    //   q     r.q     q * r.p
    return Rational(  p * r.q,
                      // ---------
                      q * r.p
                   );
  }

  // Конструктор копирования
  Rational(const Rational& r) {
    p = r.p;
    q = r.q;
  }

  // cout - типа ostream
  friend ostream& operator << (ostream& os, Rational& r) {
    os << r.p << " / " << r.q << " ";
    return os;
  }

  // stream - поток
  // thread - поток/нить
};

int main() {
  // При создании объекта вызывается конструктор
  Rational a(4, 6), b(11, 2);
  a.show();
  b.show();

  Rational c = b + a;
  c.show();

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  Rational x(1, 2), y(1, 3);
  x = x - y;
  cout << "1/2 - 1/3 = ";
  x.show();

  /* Rational x(4,6), y(1,3);
   x.add(y);
   x.show();

   Rational yy("Vvedite:");
   yy.show(); */

  return 0;
}
