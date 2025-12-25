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

Node *midRecursive(Node *slow, Node *fast) {
  if (fast == NULL || fast->next == NULL) {
    return slow;
  }

  return midRecursive(slow->next, fast->next->next);
}

int findMid(Node *head) {
  if (head == NULL)
    return -1;

  Node *ans = midRecursive(head, head->next);
  return ans->data;
}

int main() {

  auto input = takeInput();
  Node *head = input.second.first;

  // 	head = bubbleSort(head);
  // 	printLL(head);
  cout << findMid(head);
  cout << endl;
}
