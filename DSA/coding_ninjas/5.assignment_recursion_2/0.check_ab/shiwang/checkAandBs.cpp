#include <bits/stdc++.h>
using namespace std;

bool checkAandBs(string s, int n) {
  if (n >= s.size()) {
    return true;
  }

  if (n + 1 <= s.size() - 1 && s[n] == 'b' && s[n + 1] == 'b') {
    return checkAandBs(s, n + 2);
  } else if (s[n] == 'a') {
    return checkAandBs(s, n + 1);
  }
  return false;
}

int main() {
  string s;
  cin >> s;

  cout << checkAandBs(s, 0);
  return 0;
}