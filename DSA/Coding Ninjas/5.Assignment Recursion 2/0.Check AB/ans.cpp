#include <iostream>
using namespace std; 

bool f(string s){
    if(s.size() == 0) return true;
    if(s[0] == 'a') return f(s.substr(1));
    if(s.size()<=2) return false;
    if(s[1] == 'a') return false;
    if(s[2] == 'b') return false;
    return f(s.substr(2));
}

int main(){
    string s;
    cout <<"Enter the string (s) : ";
    cin >> s;
    cout << f(s);
    return 0;
}