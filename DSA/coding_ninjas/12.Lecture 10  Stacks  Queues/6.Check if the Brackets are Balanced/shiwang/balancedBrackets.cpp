#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node *next;

  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
};

template <typename T> class stackUsingLL {
  Node<T> *head;
  int length;

public:
  stackUsingLL() {
    head = NULL;
    length = 0;
  }

  void push(T data) {
    Node<T> *node = new Node<T>(data);
    node->next = head;
    head = node;
    length++;
  }

  T pop() {
    if (isEmpty())
      return T();
    Node<T> *node = head;
    head = head->next;
    node->next = NULL;
    T data = node->data;
    length--;
    delete node;
    return data;
  }

  T top() {
    if (isEmpty())
      return T();
    return head->data;
  }

  bool isEmpty() { return length == 0; }

  int size() { return length; }

  ~stackUsingLL() {
    while (head != NULL) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

bool checkBrackets(string s, stackUsingLL<char> &st1, int idx = 0) {
  if (idx == s.size()) {
    return st1.isEmpty();
  }

  if (s[idx] == '(') {
    st1.push('(');
  } else {
    if (st1.isEmpty())
      return false;
    else
      st1.pop();
  }

  return checkBrackets(s, st1, idx + 1);
}

int main() {
  stackUsingLL<char> st1;
  string s;
  cin >> s;

  if (checkBrackets(s, st1)) {
    cout << "true";
  } else {
    cout << "false";
  }
}