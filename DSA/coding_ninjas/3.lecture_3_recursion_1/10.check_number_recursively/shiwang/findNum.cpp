#include <bits/stdc++.h>
using namespace std;

bool findNum(vector<int> &arr, int n, int x) {
  if (n == arr.size())
    return false;
  if (arr[n] == x)
    return true;

  return findNum(arr, n + 1, x);
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

  cout << findNum(arr, 0, x);
  return 0;
}