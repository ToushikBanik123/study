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

void printLL(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *deleteNEveryM(Node *head, int m, int n) {
  if (n == 0) {
    return head;
  }

  if (m == 0)
    return NULL;

  Node *newHead = NULL;
  Node *newTail = NULL;
  int count1 = 0;
  int count2 = 0;

  while (head != NULL) {
    Node *temp = head->next;
    head->next = NULL;
    if (count2 == n)
      count2 = 0;

    if (count1 < m && count2 == 0) {
      if (newHead == NULL) {
        newHead = head;
        newTail = head;
      } else {
        newTail->next = head;
        newTail = head;
      }
      count1++;
    } else if (count2 < n) {
      if (count1 == m) {
        count1 = 0;
      }
      delete head;
      count2++;
    }
    head = temp;
  }

  return newHead;
}

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int m, n;
    auto input = takeInput();
    Node *head = input.second.first;
    cin >> m >> n;

    head = deleteNEveryM(head, m, n);
    printLL(head);
  }
}