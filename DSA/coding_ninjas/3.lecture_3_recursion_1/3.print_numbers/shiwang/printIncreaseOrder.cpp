#include <bits/stdc++.h>
using namespace std;

void printIncreasingOrder(int n) {
  if (n <= 0)
    return;
  printIncreasingOrder(n - 1);
  cout << n << " ";
  return;
}

int main() {
  int n;
  cin >> n;
  printIncreasingOrder(n);
  return 0;
}