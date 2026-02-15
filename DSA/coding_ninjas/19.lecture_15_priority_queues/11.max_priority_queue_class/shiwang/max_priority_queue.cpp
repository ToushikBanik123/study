#include <iostream>
#include <vector>
using namespace std;

template <typename T> class PriorityQueue {
  vector<T> pqueue;
  int nextIdx;

  void upHeapify() {
    if (isEmpty())
      return;

    int elemIdx = pqueue.size() - 1;
    int i = 0;

    while (elemIdx > 0) {
      if (elemIdx % 2 == 0) {
        i = (elemIdx - 2) / 2;
      } else {
        i = (elemIdx - 1) / 2;
      }

      if (pqueue[elemIdx] > pqueue[i]) {
        swap(pqueue[elemIdx], pqueue[i]);
        elemIdx = i;
      } else {
        break;
      }
    }
  }

  void downHeapify() {
    if (isEmpty())
      return;

    int elemIdx = 0;
    int left = 0;
    int right = 0;

    while (elemIdx < getSize()) {
      left = (2 * elemIdx) + 1;
      right = (2 * elemIdx) + 2;

      if (left < getSize() && right < getSize()) {
        if (pqueue[left] > pqueue[right]) {
          swap(pqueue[elemIdx], pqueue[left]);
          elemIdx = left;
        } else {
          swap(pqueue[elemIdx], pqueue[right]);
          elemIdx = right;
        }
      } else if (left < getSize() && pqueue[elemIdx] < pqueue[left]) {
        swap(pqueue[elemIdx], pqueue[left]);
        elemIdx = left;
      } else if (right < getSize() && pqueue[elemIdx] < pqueue[right]) {
        swap(pqueue[elemIdx], pqueue[right]);
        elemIdx = right;
      } else {
        break;
      }
    }
  }

public:
  PriorityQueue() { nextIdx = 0; }

  bool isEmpty() { return pqueue.size() == 0; }

  int getSize() { return pqueue.size(); }

  T getMax() {
    if (isEmpty())
      return 0;
    return pqueue[0];
  }

  void insert(T data) {
    pqueue.push_back(data);
    nextIdx++;
    upHeapify();
  }

  void removeMax() {
    if (isEmpty())
      return;
    swap(pqueue[0], pqueue[pqueue.size() - 1]);
    pqueue.pop_back();
    nextIdx--;
    downHeapify();
  }
};

int main() {

  // ---------- Test Case Arrays ----------
  int arr1[] = {5, 3, 8};
  int arr2[] = {1, 2, 3, 4, 5};
  int arr3[] = {5, 4, 3, 2, 1};
  int arr4[] = {4, 4, 4, 4};
  int arr5[] = {5, 3, 3, 4, 2, 2};
  int arr6[] = {10};
  int arr7[] = {9, 1};
  int arr8[] = {12, 7, 6, 10, 8, 20, 15};
  int arr9[] = {-1, -5, 3, 0, 2, -2};
  int arr10[] = {17, 3, 25, 1, 9, 14, 6, 8, 20, 4};

  int *arrays[] = {arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10};

  int sizes[] = {3, 5, 5, 4, 6, 1, 2, 7, 6, 10};

  int testCount = 10;

  // ---------- Run Tests ----------
  for (int t = 0; t < testCount; t++) {
    cout << "Test Case " << t + 1 << ": ";

    PriorityQueue<int> pq;

    for (int i = 0; i < sizes[t]; i++) {
      pq.insert(arrays[t][i]);
    }

    while (!pq.isEmpty()) {
      cout << pq.getMax() << " ";
      pq.removeMax();
    }
    cout << endl;
  }

  // ---------- Char Test ----------
  cout << "Char Test: ";
  char carr[] = {'z', 'a', 'm', 'b', 'x'};
  int cn = 5;

  PriorityQueue<char> cpq;
  for (int i = 0; i < cn; i++) {
    cpq.insert(carr[i]);
  }

  while (!cpq.isEmpty()) {
    cout << cpq.getMax() << " ";
    cpq.removeMax();
  }
  cout << endl;

  return 0;
}
