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

pair<int, pair<Node *, Node *>> takeInput() {
  int data;
  cin >> data;

  Node *head = NULL;
  Node *tail = NULL;
  int count = 0;
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
    count++;
  }
  return {count, {head, tail}};
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

Node *appendNToFirst(Node *head, Node *temp, Node *&tail, int pos, int len,
                     int count = 0) {
  if (pos <= 0 || pos >= len)
    return head;

  if (temp != NULL && count < pos - 1) {
    return appendNToFirst(head, temp->next, tail, pos, len, count + 1);
  }

  if (temp != NULL) {
    Node *node = temp->next;
    temp->next = NULL;
    tail->next = head;
    head = node;
    tail = temp;
  }
  return head;
}

void printLL(Node *head) {
  if (head == NULL) {
    return;
  }

  cout << head->data << " ";
  printLL(head->next);
}

Node *removeConsecutiveDuplicates(Node *head) {
  if (head == NULL) {
    return head;
  }

  Node *temp = head;

  while (temp != NULL) {
    if (temp->next != NULL && temp->data == temp->next->data) {
      Node *a = temp->next->next;
      delete temp->next;
      temp->next = a;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

void printLLReverse(Node *head) {
  if (head == NULL) {
    return;
  }

  printLLReverse(head->next);
  cout << head->data << " ";
}

int main() {
  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    // 		int target;
    pair<int, pair<Node *, Node *>> input = takeInput();
    Node *head = input.second.first;
    Node *tail = input.second.second;
    int len = input.first;
    // 		cin >> target;

    // 		head = appendNToFirst(head, head, tail, len - target, len);
    // head = removeConsecutiveDuplicates(head);
    // 		printLL(head);
    printLLReverse(head);
  }
}