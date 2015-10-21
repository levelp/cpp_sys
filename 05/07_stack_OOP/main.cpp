// Реализовать стек и очередь
// --------------------------------------------
#include <iostream>

using namespace std;

#define D(x) cout << #x << endl; x;

//-->
// Элемент стека и очереди
template <class T = int> // T - произвольный тип данных
struct E {
  T value; // Значение элемента
  E<T>* next; // Указатель на следующий элемент
};

// Стек
template <class T = int> // T - произвольный тип данных
struct Stack {
  typedef E<T> ET;
  ET* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(T value) {
    ET* newElement = new ET;
    // Записываем значение,
    // которое надо поместить
    // на вершину стека
    newElement->value = value;
    // Новый элемент на вершине стека
    // поэтому все остальные следуют за ним
    newElement->next = top;

    // Ставим новый элемент в начало списка
    top = newElement;
  }
  // Взять значение с вершины стека
  T pop() {
    T result = top->value; // 1. Сохраняем результат - значение элемента-"вершины" стека
    ET* e = top; // 2. Запоминаем ссылку на удаляемый элемент
    top = top->next; // 3. Перемещаем вершину стека на следующий элемент
    delete e; // 4. Реально удаляем элемент
    return result; // 5. Возвращаем результат
  }
};

template <class T = int> // T - произвольный тип данных
struct Queue {
  E<T>* head; // "Голова" - начало очереди
  E<T>* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(T value) {
    // Создаём новый элемент
    E<T>* e = new E<T>;
    e->value = value;
    e->next = NULL;

    // Если очередь пуста
    if(head == NULL) {
      head = e;
      tail = e;
    } else {
      // Если в очереди уже есть элементы
      // "Присоединяем" элемент к последнему
      // элементу в очереди
      tail->next = e;
    }
  }
  // Забрать первый элемент из очереди
  T get() {
    // Запоминаем первый элемент
    E<T>* firstElement = head;
    // Значение, которое мы в конце вернём
    T value = firstElement->value;
    // Передвигаем указатель на начало
    // очереди на следующий элемент
    head = head->next;

    // Если очередь пуста, то
    // хвост очереди не указывает ни на
    // какой элемент
    if(head == NULL)
      tail = NULL;

    // Удаляем первый элемент из
    // динамической памяти
    delete firstElement;

    // Возвращаем его значение
    return value;
  }
};
//<--

int main() {
  //-->
  D(Stack<> s);
  D(s.push(2));
  D(s.push(3));
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  D(Stack<string> strStack);
  D(strStack.push("Hello"));
  D(strStack.push("world"));
  cout << "world - " << strStack.pop() << endl;
  cout << "Hello - " << strStack.pop() << endl;

  D(Stack<> s2);
  D(s2.push(10));
  D(s.push(11));
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  D(Queue<int> q);
  D(q.put(10));
  D(q.put(14));
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;

  D(Queue<double> q2);
  D(q2.put(1.4));
  D(q2.put(4.5));
  cout << "1.4 - " << q2.get() << endl;
  cout << "4.5 - " << q2.get() << endl;
  //<--

  return 0;
}
