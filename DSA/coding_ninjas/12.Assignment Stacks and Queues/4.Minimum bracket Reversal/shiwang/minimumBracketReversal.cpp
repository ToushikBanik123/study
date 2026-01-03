#include <iostream>
#include <stack>
#include <string>

using namespace std;

int minimumBracketReversal(string &s) {
  if (s.length() % 2 != 0)
    return -1;
  if (s.length() == 0)
    return 0;

  stack<char> st1;

  for (int i = 0; i < s.length(); i++) {
    if (!st1.empty() && st1.top() == '{' && s[i] == '}') {
      st1.pop();
    } else {
      st1.push(s[i]);
    }
  }

  int count = 0;
  while (!st1.empty()) {
    char top = st1.top();
    st1.pop();

    if (top == '{' && st1.top() == '}') {
      count += 2;
    } else {
      count += 1;
    }
    st1.pop();
  }
  return count;
}

int main() {
  string s;
  cin >> s;
  cout << minimumBracketReversal(s);
}