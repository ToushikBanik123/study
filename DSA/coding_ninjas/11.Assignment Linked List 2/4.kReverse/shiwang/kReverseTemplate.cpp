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

Node<int> *kReverse(Node<int> *head, int m) {
  if (head == NULL || m < 2) {
    return head;
  }

  Node<int> *start = head;
  Node<int> *curr = head;
  Node<int> *prev = NULL;

  while (curr != NULL) {
    Node<int> *temp = prev;

    for (int i = 0; i < m && curr != NULL; i++) {
      Node<int> *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    if (temp == NULL) {
      head = prev;
    } else {
      temp->next = prev;
    }
    prev = start;
    start->next = curr;
    start = curr;
  }

  return head;
}

int main() {
  Node<int> *head = takeInput();
  int m;
  cin >> m;

  head = kReverse(head, m);

  printLL(head);
}