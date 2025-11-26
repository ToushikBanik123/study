#include <iostream>
#include <string>
using namespace std;

bool checkTheSequence(string &s, string &t){
    int sn = s.size();
    int tn = t.size();
    int j = 0;
    for(int i = 0; i < sn; i++){
        if(s[i] == t[j]){
            j++;
            if(tn <= j) return true;
        }
    }
    return false;
}

bool checkSequenceRecursive(string &s, string &t, int si, int ti) {
      // Base case 1: All characters of t matched
      if (ti == t.size()) return true;

      // Base case 2: Reached end of s without matching all of t
      if (si == s.size()) return false;

      // If current characters match, move both pointers
      if (s[si] == t[ti]) {
          return checkSequenceRecursive(s, t, si + 1, ti + 1);
      }

      // If not matched, move only s pointer
      return checkSequenceRecursive(s, t, si + 1, ti);
  }

  bool checkTheSequence(string &s, string &t) {
      return checkSequenceRecursive(s, t, 0, 0);
}

int main(){
    string s,t;
    cout << "Enter the value of the string (s) : ";
    cin >> s;
    cout << "Enter the value of the strig (t) : ";
    cin >> t;
    if(checkTheSequence(s,t)){
    cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}