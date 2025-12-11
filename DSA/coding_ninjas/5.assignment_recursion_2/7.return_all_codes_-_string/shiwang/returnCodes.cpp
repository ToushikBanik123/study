#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void returnCodes(const string &s, int idx, vector<char> &alphabets,
                   string &current, vector<string> &result) {
    if (idx == s.size()) {
      result.push_back(current);
      return;
    }
    int num = 0;
    for (int i = idx; i < s.size(); i++) {
      num = num * 10 + (s[i] - '0');
      if (num >= alphabets.size())
        break;
      current.push_back(alphabets[num]);
      returnCodes(s, i + 1, alphabets, current, result);
      current.pop_back();
    }
  }
};

int main() {
  string s;
  cin >> s;

  Solution s1;
  string current = "";
  vector<char> alphabets = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                            'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  vector<string> result;
  s1.returnCodes(s, 0, alphabets, current, result);
  for (auto i : result) {
    cout << i << endl;
  }
  return 0;
}