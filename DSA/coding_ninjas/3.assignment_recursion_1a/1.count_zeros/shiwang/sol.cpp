#include <bits/stdc++.h>
using namespace std;

// time complexity: O(d) where d is the number of digits in n
// space complexity: O(d) due to recursive call stack

int countZeros(int n) {
  if (n == 0) {
    return 1;
  }
  if (n < 10)
    return 0;

  int quotient = countZeros(n / 10);
  int remainder = n % 10;
  if (remainder == 0) {
    return quotient + 1;
  } else {
    return quotient;
  }
}

int main() {
  int n;
  cin >> n;
  cout << countZeros(n) << endl;
  return 0;
}