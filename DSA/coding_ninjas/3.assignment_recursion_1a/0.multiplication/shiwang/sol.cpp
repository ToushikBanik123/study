#include <bits/stdc++.h>
using namespace std;


// time complexity: O(n)
// space complexity: O(n) due to recursive call stack

int multiply(int m, int n) {
  if (n == 0) {
    return 0;
  }
  return m + multiply(m, n - 1);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiply(m, n) << endl;
    return 0;
}