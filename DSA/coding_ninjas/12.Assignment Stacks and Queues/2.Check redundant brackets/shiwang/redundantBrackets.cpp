#include<iostream>
#include<stack>
using namespace std;

bool redundantBrackets(string &s, stack<char>& s1, int idx) {
	if(idx == s.length()) return false;

	if(s[idx] == ')') {
		int count = 0;
		while(!s1.empty() && s1.top() != '(') {
			s1.pop();
			count++;
		}

		if(!s1.empty()) s1.pop();
		if (count <= 1) return true;
	} else {
		s1.push(s[idx]);
	}

	return redundantBrackets(s, s1, idx + 1);
}

int main() {
	string s;
	cin >> s;

	stack<char> s1;

	cout << redundantBrackets(s, s1, 0);
}