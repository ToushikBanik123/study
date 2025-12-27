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

Node<int> *deleteNEveryM(Node<int> *head, int m, int n) {
  if (head == NULL || n == 0)
    return head;

  Node<int> *curr = head;
  Node<int> *prev = NULL;

  while (curr != NULL) {

    for (int i = 0; i < m && curr != NULL; i++) {
      prev = curr;
      curr = curr->next;
    }

    for (int i = 0; i < n && curr != NULL; i++) {
      Node<int> *temp = curr;
      curr = curr->next;
      delete temp;
    }

    if (prev != NULL)
      prev->next = curr;
  }

  return head;
}

int main() {
  Node<int> *head = takeInput();
  int m, n;
  cin >> m >> n;
  head = deleteNEveryM(head, m, n);
  printLL(head);
}