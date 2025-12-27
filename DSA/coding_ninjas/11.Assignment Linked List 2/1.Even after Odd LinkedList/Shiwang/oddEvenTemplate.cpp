#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node<T> *next;

  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
};

Node<int> *takeInput() {
  int data;
  cin >> data;

  Node<int> *head = NULL;
  Node<int> *tail = NULL;

  while (data != -1) {
    Node<int> *node = new Node<int>(data);
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    cin >> data;
  }

  return head;
}

void printLL(Node<int> *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node<int> *oddBeforeEven(Node<int> *head) {
  if (head == NULL || head->next == NULL)
    return head;

  Node<int> *oddHead = NULL;
  Node<int> *oddTail = NULL;
  Node<int> *evenHead = NULL;
  Node<int> *eventail = NULL;

  while (head != NULL) {
    Node<int> *temp = head->next;
    head->next = NULL;
    if (head->data % 2 == 0) {
      if (evenHead == NULL) {
        evenHead = head;
        eventail = head;
      } else {
        eventail->next = head;
        eventail = head;
      }
    } else {
      if (oddHead == NULL) {
        oddHead = head;
        oddTail = head;
      } else {
        oddTail->next = head;
        oddTail = head;
      }
    }
    head = temp;
  }

  if (oddTail != NULL) {
    oddTail->next = evenHead;
    return oddHead;
  }

  return evenHead;
}

int main() {
  Node<int> *head = takeInput();
  head = oddBeforeEven(head);
  printLL(head);
}