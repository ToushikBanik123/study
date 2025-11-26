#include <iostream>
using namespace std;

void convertTheChar(string &str, char ch1, char ch2, int i){
    if(i>=str.length()) return;
    if(str[i] == ch1){
        str[i] = ch2;
    }
    convertTheChar(str,ch1,ch2, i+1);
}

int main(){
    string str;
    char ch1,ch2;
    cout << "Enter the string : ";
    cin >> str;
    cout << "Enter the value of ch1 : ";
    cin >> ch1;
    cout << "Enter the value of ch2 : ";
    cin >> ch2;
    convertTheChar(str,ch1,ch2,0);
    cout << "This is this the final string : " << str << endl;
    return 0;
}
