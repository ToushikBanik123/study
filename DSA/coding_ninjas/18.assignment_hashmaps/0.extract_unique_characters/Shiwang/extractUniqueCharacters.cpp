#include <iostream>
#include <unordered_map>
using namespace std;

string removeDuplicates(string s) {
  unordered_map<char, bool> charMap;
  string ans = "";

  for (char ch : s) {
    if (charMap.find(ch) != charMap.end()) {
      continue;
    }
    ans += ch;
    charMap[ch] = true;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << s << endl;
  string ans = removeDuplicates(s);
  cout << ans;
}