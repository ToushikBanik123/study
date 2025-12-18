#include <bits/stdc++.h>
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
    Node *newNode = new Node(data);

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    cin >> data;
  }
  return head;
}

int findIndex(Node *head, int target, int count = 0) {
  if (head == NULL) {
    return -1;
  }

  if (head->data == target) {
    return count;
  }

  return findIndex(head->next, target, count + 1);
}

int main() {
  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    int target;
    Node *head = takeInput();
    cin >> target;

    cout << findIndex(head, target);
  }
}