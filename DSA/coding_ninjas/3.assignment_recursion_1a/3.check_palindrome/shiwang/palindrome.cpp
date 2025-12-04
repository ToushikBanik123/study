#include <bits/stdc++.h>
using namespace std;


// time complexity: O(n) where n is the length of the string
// space complexity: O(n) due to recursive call stack

bool palindrome(string &s, int start, int end) {
  if (s.empty())
    return true;
  if (start >= end)
    return true;
  if (s[start] != s[end])
    return false;

  return palindrome(s, start + 1, end - 1);
}

int main() {
  string s;
  cin >> s;
  cout << palindrome(s, 0, s.size() - 1);
  return 0;
}