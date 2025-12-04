#include <bits/stdc++.h>
using namespace std;

void replacePi(string s, int n, string &result) {
  if (n >= s.size())
    return;

  if (n == s.size() - 1) {
    result.push_back(s[n]);
    return;
  }

  if (s[n] == 'p' && s[n + 1] == 'i') {
    result += "3.14";
    replacePi(s, n + 2, result);
  } else {
    result.push_back(s[n]);
    replacePi(s, n + 1, result);
  }
  return;
}

int main() {
  string s;
  cin >> s;

  string result = "";

  replacePi(s, 0, result);
  cout << result;
  return 0;
}