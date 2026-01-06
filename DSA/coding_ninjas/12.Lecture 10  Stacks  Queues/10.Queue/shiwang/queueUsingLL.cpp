#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T data;
  Node<T> *next;

  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
};

template <typename T> class queueUsingLL {
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  queueUsingLL() {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  void enqueue(T val) {
    Node<T> *node = new Node<T>(val);
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    size++;
  }

  bool empty() { return size == 0; }

  T dequeue() {
    if (empty())
      return T();
    Node<T> *temp = head->next;
    T data = head->data;
    delete head;
    head = temp;
    size--;
    return data;
  }

  int sizeOf() { return size; }

  T front() {
    if (empty())
      return T();
    return head->data;
  }

  ~queueUsingLL() {
    while (head != NULL) {
      Node<T> *temp = head->next;
      delete head;
      head = temp;
    }
  }
};

int main() {
  queueUsingLL<int> q1;

  cout << q1.front() << endl;
  q1.enqueue(3);
  q1.enqueue(6);
  q1.enqueue(5);
  q1.enqueue(2);
  q1.enqueue(8);
  cout << q1.sizeOf() << endl;
  cout << q1.front() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  q1.enqueue(1);
  q1.enqueue(4);
  cout << q1.front() << endl;
}