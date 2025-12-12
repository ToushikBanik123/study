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

int findLength(Node *head) {
  Node *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

int printIthElement(Node *head, int i) {
  Node *temp = head;

  if (i == 0) {
    return temp->data;
  }

  int count = 0;
  while (temp != NULL && count < i) {
    temp = temp->next;
    count++;
  }

  if (temp != NULL) {
    return temp->data;
  }
  return -1;
}

int main() {
  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    int k;
    Node *head = takeInput();
    cin >> k;
    cout << endl;
    // 		cout << findLength(head);
    int ele = printIthElement(head, k);
    if(ele == -1) cout << endl;
    else cout << ele << endl;
  }
}