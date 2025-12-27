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

Node<int> *swapNodes(Node<int> *head, int m, int n) {
  if (head == NULL || head->next == NULL || m == n)
    return head;

  Node<int> *prev1 = NULL;
  Node<int> *prev2 = NULL;
  Node<int> *curr1 = head;
  Node<int> *curr2 = head;

  for (int i = 0; i < m && curr1->next != NULL; i++) {
    prev1 = curr1;
    curr1 = curr1->next;
  }

  for (int i = 0; i < n && curr2->next != NULL; i++) {
    prev2 = curr2;
    curr2 = curr2->next;
  }

  if (prev1 != NULL) {
    prev1->next = curr2;
  } else {
    head = curr2;
  }

  if (prev2 != NULL) {
    prev2->next = curr1;
  } else {
    head = curr1;
  }

  Node<int> *temp = curr1->next;
  curr1->next = curr2->next;
  curr2->next = temp;

  return head;
}

int main() {
  Node<int> *head = takeInput();
  int m, n;
  cin >> m >> n;
  head = swapNodes(head, m, n);
  printLL(head);
}