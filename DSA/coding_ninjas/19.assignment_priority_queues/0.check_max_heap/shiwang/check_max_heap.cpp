#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool checkMaxHeap(vector<int> &input) {

  for (int i = 0; i <= (input.size() / 2) - 1; i++) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < input.size() && input[left] > input[i])
      return false;
    if (right < input.size() && input[right] > input[i])
      return false;
  }

  return true;
}

int main() {
  int n;
  cin >> n;

  vector<int> input;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    input.push_back(data);
  }

  cout << checkMaxHeap(input);
}