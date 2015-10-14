<!-- doc.py -->
Работа с динамическим списком
-----------------------------
Реализовать:
* добавление в начало списка addToBegin(int value)
* добавление в конец списка addToEnd(int value)
* удаление из начала списка deleteFromBegin
* удаление из конца списка deleteFromEnd
* показать весь список show()
Элемент
``` cpp
struct ListElement {
  int value;
  // ListElement* prev; // Предыдущий элемент
  ListElement* next;
};
```

[main.cpp](main.cpp)

