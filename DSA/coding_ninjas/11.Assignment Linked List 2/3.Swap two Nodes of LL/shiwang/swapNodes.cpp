#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node *takeInput() {
  int data;
  cin >> data;

  Node *head = NULL;
  Node *tail = NULL;

  while (data != -1) {
    Node *node = new Node(data);
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

void printLL(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *swapNodes(Node *head, int m, int n) {
  if (head == NULL || m == n) {
    return head;
  }

  Node *prev1 = NULL;
  Node *prev2 = NULL;
  Node *curr1 = head;
  Node *curr2 = head;

  for (int i = 0; i < m; i++) {
    prev1 = curr1;
    curr1 = curr1->next;
  }

  for (int i = 0; i < n; i++) {
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

  Node *temp = curr1->next;
  curr1->next = curr2->next;
  curr2->next = temp;

  return head;
}

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    Node *head = takeInput();
    int m, n;
    cin >> m >> n;

    head = swapNodes(head, m, n);
    printLL(head);
  }
}