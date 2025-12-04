#include <bits/stdc++.h>
using namespace std;

// time complexity: O(k)
// space complexity: O(k) due to recursive call stack


float geometricSum(int k) {

  if (k == 0)
    return 1;

  return (1 / pow(2.0, k)) + geometricSum(k - 1);
}

int main() {
  int k;
  cin >> k;
  cout << geometricSum(k);
  return 0;
}