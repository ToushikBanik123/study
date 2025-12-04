#include <bits/stdc++.h>
using namespace std;

int arraySum(vector<int> &arr, int n) {
  if (n == 0)
    return arr[0];

  return arr[n] + arraySum(arr, n - 1);
}

int main() {
  int n;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }

  cout << arraySum(arr, n);
  return 0;
}