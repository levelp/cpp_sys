/// Работа с динамическим списком
/// -----------------------------
/// Реализовать:
/// * добавление в начало списка addToBegin(int value)
/// * добавление в конец списка addToEnd(int value)
/// * удаление из начала списка deleteFromBegin
/// * удаление из конца списка deleteFromEnd
/// * показать весь список show()

#include <iostream>

using namespace std;

/// Элемент
//-->
struct ListElement {
  int value;
  // ListElement* prev; // Предыдущий элемент
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
  addToBegin(2);
  showList();

  addToBegin(10);
  showList();

  addToBegin(-6);
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  return 0;
}
