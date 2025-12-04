#include <bits/stdc++.h>
using namespace std;

int convertStringToNum(string s, int n) {
  if (n == s.size())
    return 0;
  int num = s[n] - '0';
  return num * pow(10, s.size() - 1 - n) + convertStringToNum(s, n + 1);
}

int main() {
  string s;
  cin >> s;

  string result = "";

  cout << convertStringToNum(s, 0);
  return 0;
}