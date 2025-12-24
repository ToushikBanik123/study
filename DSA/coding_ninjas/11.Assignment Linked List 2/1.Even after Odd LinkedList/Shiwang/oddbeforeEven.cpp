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
    Node *node = new Node(data);
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    count++;
    cin >> data;
  }
  return {count, {head, tail}};
}

int findTargetIndex(Node *head, int target, int count = 0) {
  if (head == NULL) {
    return -1;
  }

  if (head->data == target) {
    return count;
  }
  return findTargetIndex(head->next, target, count + 1);
}

Node *oddBeforeEven(Node *head) {
  Node *even = NULL;
  Node *evenTail = NULL;
  Node *odd = NULL;
  Node *oddTail = NULL;

  while (head != NULL) {
    Node *nextNode = head->next; // save next
    head->next = NULL;           // detach node

    if (head->data % 2 == 0) {
      if (even == NULL) {
        even = evenTail = head;
      } else {
        evenTail->next = head;
        evenTail = head;
      }
    } else {
      if (odd == NULL) {
        odd = oddTail = head;
      } else {
        oddTail->next = head;
        oddTail = head;
      }
    }
    head = nextNode;
  }

  if (oddTail != NULL) {
    oddTail->next = even;
    return odd;
  }

  return even;
}

void printLL(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int target;
    auto input = takeInput();
    Node *head = input.second.first;
    // 		cin >> target;
    //      cout << findTargetIndex(head, target);
    // 		printLL(head);
    head = oddBeforeEven(head);
    printLL(head);
  }
}