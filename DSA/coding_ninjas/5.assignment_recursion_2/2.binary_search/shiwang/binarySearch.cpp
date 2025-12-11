#include <bits/stdc++.h>
using namespace std;

int bSearch(vector<int> &arr, int x, int l, int r) {
  if (l > r)
    return -1;

  int m = l + (r - l) / 2;
  if (arr[m] == x)
    return m;
  else if (arr[m] > x)
    return bSearch(arr, x, l, m - 1);
  else
    return bSearch(arr, x, m + 1, r);
}

int main() {
  int n, x;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  cin >> x;
  cout << bSearch(arr, x, 0, n - 1);
  return 0;
}