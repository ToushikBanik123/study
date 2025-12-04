#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c) {
  if (n == 1) {
    cout << "from " << a << " to " << b << endl;
    return;
  }

  towerOfHanoi(n - 1, a, c, b);
  cout << "from " << a << " to " << b << endl;
  towerOfHanoi(n - 1, c, b, a);
}

int main() {
  int n;
  cin >> n;

  towerOfHanoi(n, 'A', 'B', 'C');
  return 0;
}