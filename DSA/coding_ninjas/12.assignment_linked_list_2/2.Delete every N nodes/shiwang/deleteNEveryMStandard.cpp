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

Node *deleteNEveryMStandard(Node *head, int m, int n) {
  if (head == NULL || n == 0)
    return head;
  if (m == 0)
    return NULL;

  Node *curr = head;
  Node *prev = NULL;

  while (curr != NULL) {

    for (int i = 0; i < m && curr != NULL; i++) {
      prev = curr;
      curr = curr->next;
    }

    for (int i = 0; i < n && curr != NULL; i++) {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }

    if (prev != NULL) {
      prev->next = curr;
    }
  }

  return head;
}

Node *deleteNEveryMStandardRecursive(Node *head, int m, int n) {
  if (head == NULL || n == 0)
    return head;

  if (m == 0)
    return NULL;

  Node *curr = head;
  Node *prev = NULL;

  while (curr != NULL) {

    for (int i = 0; i < m && curr != NULL; i++) {
      prev = curr;
      curr = curr->next;
    }

    for (int i = 0; i < n && curr != NULL; i++) {
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }

    if (prev != NULL) {
      prev->next = curr;
    }
  }

  return head;
}

Node *deleteNEveryMRecursion(Node *head, int m, int n) {
  if (head == NULL || n == 0)
    return head;
  if (m == 0)
    return NULL;

  Node *curr = head;

  for (int i = 1; i < m && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr == NULL)
    return head;

  Node *temp = curr->next;
  for (int i = 0; i < n && temp != NULL; i++) {
    Node *del = temp;
    temp = temp->next;
    delete del;
  }

  curr->next = deleteNEveryMRecursion(temp, m, n);
  return head;
}

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    // 1️⃣ Read linked list first
    auto input = takeInput();
    Node *head = input.second.first;

    // 2️⃣ Then read m and n
    int m, n;
    cin >> m >> n;

    // 3️⃣ Process
    // head = deleteNEveryMStandard(head, m, n);
    head = deleteNEveryMRecursion(head, m, n);
    // 4️⃣ Print
    printLL(head);
    cout << endl;
  }
}
