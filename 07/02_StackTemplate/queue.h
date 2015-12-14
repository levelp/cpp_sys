#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

// �������, ������������� �����
// ������������ ������
template <class T> // T - ��� ��������� � �����
class Queue {
  struct Element {
    T value; // ��������
    Element* next; // ��������� �������
    Element() : next(NULL) {}
  };
  Element* head,// ������ �������
           *tail; // ����� (�����) �������
 public:
  Queue() : head(NULL), tail(NULL) {}
  // �������� � ����� �������
  void put(T v) {
    Element* x = new Element;
    x->value = v;

    if(head == NULL) {
      x->next = tail;
      head = x;
    } else {
      x->next = tail;
      tail = x;
    }

  }
  // �������� �� ������ �������
  T get() {
    if(head == NULL && tail == NULL) {
      std::cout << "Queue is empty!" << std::endl;
      throw "Queue is empty!";
    }

    if(head != tail->next) {
      Element* y = head;
      T value = y->value;
      head = tail->next;
      delete y;
      return value;
    } else {
      Element* y = tail;
      T value = y->value;
      tail = tail->next;
      delete y;
      return value;
    }


  }

};

#endif // QUEUE_H_INCLUDED

