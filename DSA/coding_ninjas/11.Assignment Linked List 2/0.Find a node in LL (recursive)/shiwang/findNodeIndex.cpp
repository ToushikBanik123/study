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

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int target;
    auto input = takeInput();
    Node *head = input.second.first;
    cin >> target;

    cout << findTargetIndex(head, target);
  }
}