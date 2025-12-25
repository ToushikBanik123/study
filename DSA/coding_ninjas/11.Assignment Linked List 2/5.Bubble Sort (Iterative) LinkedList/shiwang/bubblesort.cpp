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

Node *bubbleSort(Node *head, int len) {
  if (head == NULL || len == 1) {
    return head;
  }

  int count1 = 0;

  while (count1 < len) {
    Node *curr = head;
    Node *prev = NULL;
    int count2 = 0;
    while (curr->next != NULL && count2 < (len - count1) - 1) {
      if (curr->data > curr->next->data) {
        Node *nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = curr;
        if (prev == NULL) {
          head = nextNode;
          prev = head;
        } else {
          prev->next = nextNode;
          prev = nextNode;
        }
      } else {
        prev = curr;
        curr = curr->next;
      }
      count2++;
    }
    count1++;
  }
  return head;
}

Node *bubbleSortStandard(Node *head) {
  if (head == NULL) {
    return head;
  }

  Node *end = NULL;
  bool swapped = true;

  while (swapped) {
    Node *curr = head;
    Node *prev = NULL;
    swapped = false;

    while (curr->next != end) {
      if (curr->data > curr->next->data) {
        Node *nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = curr;
        if (prev == NULL) {
          head = nextNode;
          prev = head;
        } else {
          prev->next = nextNode;
          prev = nextNode;
        }
        swapped = true;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    end = curr;
  }
  return head;
}

int main() {

  auto input = takeInput();
  Node *head = input.second.first;
  int len = input.first;

  head = bubbleSort(head, len);
  printLL(head);
  cout << endl;
}
