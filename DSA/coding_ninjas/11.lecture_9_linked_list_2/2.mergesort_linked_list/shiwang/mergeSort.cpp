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

void printLL(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *findMid(Node *head) {
  if (head == NULL) {
    return head;
  }

  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *merge(Node *head1, Node *head2) {
  Node *head = NULL;
  Node *tail = NULL;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      if (head == NULL) {
        head = head1;
        tail = head1;
      } else {
        tail->next = head1;
        tail = head1;
      }
      head1 = head1->next;
    } else {
      if (head == NULL) {
        head = head2;
        tail = head2;
      } else {
        tail->next = head2;
        tail = head2;
      }
      head2 = head2->next;
    }
  }

  while (head1 != NULL) {
    tail->next = head1;
    tail = head1;
    head1 = head1->next;
  }

  while (head2 != NULL) {
    tail->next = head2;
    tail = head2;
    head2 = head2->next;
  }

  return head;
}

Node *mergeSort(Node *head) {
  if (head->next == NULL) {
    return head;
  }

  Node *mid = findMid(head);
  Node *midNext = mid->next;
  mid->next = NULL;

  Node *left = mergeSort(head);
  Node *right = mergeSort(midNext);

  return merge(left, right);
}

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    auto input = takeInput();
    Node *head = input.second.first;
    Node *tail = input.second.second;
    int len = input.first;
    // 		cout << findMid(head)->data;
    head = mergeSort(head);
    printLL(head);
    cout << endl;
  }
}