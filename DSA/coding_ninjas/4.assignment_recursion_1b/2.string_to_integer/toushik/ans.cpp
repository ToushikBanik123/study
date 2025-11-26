#include <iostream>
#include <string>
using namespace std;

// Single parameter approach:
// int stringToNumber(string str) {
//       if(str.empty()) return 0;
//       if(str.length() == 1) return str[0] - '0';

//       int lastDigit = str.back() - '0';
//       str.pop_back();
//       return stringToNumber(str) * 10 + lastDigit;
// }


// Most efficient recursive (your current style improved):
// int stringToNumber(const string& str, int i = 0) {
//     if(i >= str.length()) return 0;
//     return (str[i] - '0') * pow(10, str.length()-1-i) + stringToNumber(str, i+1);
// }

int stringToNumber(const string& str, int i = 0, int num = 0) {
      if(i >= str.length()) return num;
      return stringToNumber(str, i+1, num*10 + (str[i]-'0'));
  }

int main(){
    string str;
    cout << "Enter your string : ";
    cin >> str;
    cout << stringToNumber(str,0,0);
    return 0;
}