#include <bits/stdc++.h>
using namespace std;

void findNumAllIndex(vector<int> &arr, int n, int x, vector<int> &result) {
  if (n == arr.size())
    return;
  if (arr[n] == x)
    result.push_back(n);

  findNumAllIndex(arr, n + 1, x, result);
}

int main() {
  int n, x;
  cin >> n;

  vector<int> arr;
  vector<int> result;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }

  cin >> x;

  findNumAllIndex(arr, 0, x, result);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}