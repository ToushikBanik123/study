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
    Node *n = new Node(data);
    if (head == NULL) {
      head = n;
      tail = n;
    } else {
      tail->next = n;
      tail = n;
    }
    cin >> data;
  }
  return head;
}

Node *deleteNode(Node *head, int pos) {
  Node *temp = head;

  if (pos == 0) {
    Node *a = temp->next;
    delete temp;
    temp = a;
    return temp;
  }
  int count = 0;
  while (temp != NULL && count < pos - 1) {
    temp = temp->next;
    count++;
  }

  if (temp != NULL) {
    Node *a = temp->next->next;
    delete temp->next;
    temp->next = a;
  }
  return head;
}

void printLL(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int LLlengthRecursive(Node *head) {
  if (head == NULL) {
    return 0;
  }

  return 1 + LLlengthRecursive(head->next);
}

Node *insertNodeRecursive(Node *head, int pos, int data, int count = 0) {
  if (pos == 0) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
  }

  Node *temp = head;

  if (temp != NULL && count < pos - 1) {
    insertNodeRecursive(temp->next, pos, data, count + 1);
    return head;
  }

  if (temp != NULL) {
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  return head;
}

int main() {
  // 	int tc;
  // 	cin >> tc;
  // 	for(int i = 0; i < tc; i++) {
  // 		int pos;
  // 		Node* head = takeInput();
  // 		cin >> pos;

  // 		int LLlength(Node* head){
  // 		    Node* temp = head;

  // 		}
  // 		head = deleteNode(head, pos);
  // 		printLL(head);
  // 	}

  Node *head = takeInput();
  int pos, data;
  cin >> pos;
  cin >> data;
  // 	cout << LLlengthRecursive(head);
  head = insertNodeRecursive(head, pos, data, 0);
  printLL(head);
}