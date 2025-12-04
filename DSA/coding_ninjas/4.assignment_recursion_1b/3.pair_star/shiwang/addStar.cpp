#include <bits/stdc++.h>
using namespace std;

string addStar(string s, int n) {
  if (n == s.size() - 1) {
    string current = "";
    current.push_back(s[n]);
    return current;
  }

  string current = "";

  current.push_back(s[n]);
  if (s[n] == s[n + 1]) {
    current += "*";
  }

  current += addStar(s, n + 1);
  return current;
}

int main() {
  string s;
  cin >> s;

  cout << addStar(s, 0);
  return 0;
}