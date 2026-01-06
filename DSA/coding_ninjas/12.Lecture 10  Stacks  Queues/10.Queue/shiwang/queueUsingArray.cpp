#include <iostream>
using namespace std;

template <typename T> class queueUsingArray {
  T *data;
  int frontIdx;
  int nextIdx;
  int size;
  int capacity;

public:
  queueUsingArray(int sz) {
    data = new T[sz];
    frontIdx = -1;
    nextIdx = 0;
    size = 0;
    capacity = sz;
  }

  void enqueue(T val) {
    if (size == capacity) {
      T *newData = new T[2 * capacity];
      int j = 0;
      for (int i = frontIdx; i < capacity; i++) {
        newData[j] = data[i];
        j++;
      }

      for (int i = 0; i < frontIdx; i++) {
        newData[j] = data[i];
        j++;
      }

      frontIdx = 0;
      nextIdx = capacity;
      capacity *= 2;
      delete[] data;
      data = newData;
    }
    if (frontIdx == -1)
      frontIdx++;
    data[nextIdx] = val;
    nextIdx = (nextIdx + 1) % capacity;
    size++;
  }

  bool empty() { return size == 0; }

  T dequeue() {
    if (empty())
      return T();
    int front = frontIdx;
    frontIdx = (frontIdx + 1) % capacity;
    size--;
    return data[front];
  }

  int sizeOf() { return size; }

  T front() {
    if (empty())
      return T();
    return data[frontIdx];
  }
};

int main() {
  queueUsingArray<int> q1(5);

  cout << q1.front() << endl;
  q1.enqueue(3);
  q1.enqueue(6);
  q1.enqueue(5);
  q1.enqueue(2);
  q1.enqueue(8);
  cout << q1.sizeOf() << endl;
  cout << q1.front() << endl;

  q1.enqueue(1);
  q1.enqueue(4);
  cout << q1.front() << endl;
}