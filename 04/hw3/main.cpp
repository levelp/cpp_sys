/// Работа с динамическим списком
/// -----------------------------
/// Реализовать:
/// * добавление в конец списка addToEnd(int value)
/// * удаление из конца списка deleteFromEnd


#include <iostream>

using namespace std;

/// Элемент
//-->
struct ListElement {
  int value;
  //ListElement* prev; // Предыдущий элемент
  ListElement* next;
};
//<--

// Указатель на первый элемент списка
ListElement* root = NULL;

// Добавить в начало списка
void addToBegin(int newValue) {
  cout << endl;
  cout << "addToBegin " << newValue << endl;
  ListElement* newElement = new ListElement;
  newElement->value = newValue;
  newElement->next = root; // NULL;

  root = newElement;
}


void addToEnd(int newValue) {
  cout << endl;
  cout << "addToEnd " << newValue << endl;

  // Сначала создаём новый элемент, т.к
  // он нам понадобится в любом случае
  ListElement* newElement = new ListElement;
  newElement->value = newValue;
  newElement->next = NULL;

  // Если список пуст, то новый элемент будет
  // единственным в списке
  if(root == NULL) {
    root = newElement;
    return;
  }
  // Список уже содержит элементы

  // Ищем последний элемент
  ListElement* last = root;
  while(last->next != NULL)
    last = last->next;
  // Теперь last - последний элемент
  // "прицепляем" новый элемент к последнему
  last->next = newElement;
}


void deleteLast() {
  if(root == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  ListElement* prevElement = NULL;
  ListElement* lastElement = root;

  while(lastElement->next != NULL) {
    prevElement = lastElement;
    lastElement = lastElement->next;
  }

  cout << endl;
  //cout << "deleteLast " << ppElement->value << endl;
  cout << "deleteLast " << lastElement->value << endl;
  //cout << "deleteLast " << lastElement->value << endl;

  // Предыдущий элемент становится последним
  prevElement->next = NULL;

  // Удаляем последний элемент
  delete lastElement;
}


// Удалить первый элемент списка
void deleteFirst() {
  // Проверяем что список пуст
  // и если это так, выводим сообщение
  // об ошибке и выходим из функции
  if(root == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  // Запоминаем ссылку на перый элемент
  ListElement* firstElement = root;
  cout << endl;
  cout << "deleteFirst " << firstElement->value << endl;

  // Переместим корень (указатель на начало
  // списка) на второй элемент
  root = firstElement->next;

  // Теперь мы можем удалить первый элемент
  // т.к. ссылка на второй элемент
  // уже сохранена
  delete firstElement;
}

void showList() {
  cout << "List: " << endl;
  ListElement* curElement = root;

  while(curElement != NULL) {
    cout << curElement->value << endl;
    curElement = curElement->next;
  }
}

int main() {
  addToEnd(-1);
  showList();
  addToBegin(2);
  showList();

  addToBegin(10);
  showList();

  addToBegin(-6);
  showList();

  addToEnd(55);
  showList();
  deleteLast();
  showList();
  deleteLast();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  return 0;
}
