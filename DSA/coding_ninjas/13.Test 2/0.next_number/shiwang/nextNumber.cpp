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
  if (head == NULL)
    return;

  cout << head->data << " ";
  printLL(head->next);
}

void incrementBy1(Node<int> *head, Node<int> *&trueHead) {
  if (head->next == NULL) {
    int data = head->data + 1;
    head->data = data % 10;
    return;
  }

  incrementBy1(head->next, trueHead);
  if (head->next->data == 0) {
    head->data += 1;
  }

  if (head->data == 10) {
    head->data %= 10;

    if (head == trueHead) {
      Node<int> *newNode = new Node<int>(1);
      newNode->next = trueHead;
      trueHead = newNode;
    }
  }
}

void incrementBy1(Node<int> *&head) {
  if (head == NULL) {
    head = new Node<int>(1);
    return;
  }
  incrementBy1(head, head);
}

int main() {
  Node<int> *head = takeInput();
  incrementBy1(head);
  printLL(head);
}