#include <iostream>

using namespace std;

// Класс "Очередь"
class Queue {
  const static int SIZE = 100;
  int data[SIZE];
  int head = 0; // Начало очереди
  int tail = -1; // Хвост очереди
 public:
  // == Добавили 1 ==
  // head
  // -------------------------
  // | 1 |   |   |   |   |   |
  // -------------------------
  // tail
  // == Добавили 2 ==
  // head
  // -------------------------
  // | 1 | 2 |   |   |   |   |
  // -------------------------
  //     tail
  // head
  // -------------------------
  // | 1 | 2 | 3 |   |   |   |
  // -------------------------
  //         tail
  //     head
  // -------------------------
  // |   | 2 | 3 |   |   |   |
  // -------------------------
  //         tail
  //         head
  // -------------------------
  // |   |   | 3 |   |   |   |
  // -------------------------
  //         tail
  // Добавить в конец очереди
  void put(int v) {
    ++tail;
    data[tail] = v;
  }
  // Извлечь из начала очереди
  int get() {
    return data[head++];
  }
  // Текущий размер очереди
  int size() {
    return tail - head + 1;
  }
};

int main() {
  Queue q;
  q.put(1);
  q.put(2);
  cout << q.get() << endl;
  q.put(3);
  cout << q.get() << endl;
  cout << q.get() << endl;
  return 0;
}
