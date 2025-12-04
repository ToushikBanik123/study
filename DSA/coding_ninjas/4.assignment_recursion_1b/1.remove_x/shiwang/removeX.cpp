#include <bits/stdc++.h>
using namespace std;

void removeX(string s, int n, string &result) {
  if (n >= s.size())
    return;

  if (s[n] != 'x') {
    result.push_back(s[n]);
  }

  removeX(s, n + 1, result);
}

int main() {
  string s;
  cin >> s;

  string result = "";

  removeX(s, 0, result);
  cout << result;
  return 0;
}