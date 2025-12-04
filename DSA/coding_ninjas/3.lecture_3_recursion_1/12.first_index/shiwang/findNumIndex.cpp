#include <bits/stdc++.h>
using namespace std;

int findNumIndex(vector<int> &arr, int n, int x) {
  if (n == arr.size())
    return -1;
  if (arr[n] == x)
    return n;

  return findNumIndex(arr, n + 1, x);
}

int main() {
  int n, x;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }

  cin >> x;

  cout << findNumIndex(arr, 0, x);
  return 0;
}