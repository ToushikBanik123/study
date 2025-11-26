#include <iostream>
#include <string>
using namespace std;

//With an TC of (O(n2)) and an SC of (O(n2))
string addStars(string str, int i){
    if(i <= str.length() - 2){
        if(str[i] == str[i+1]){
            str.insert(i+1,1,'*');
            return addStars(str,i+2);
        }
        return addStars(str,i+1);
    }
    return str;
}

string onSecondString(string str1, string str2, int i){
    if(str1.length() == 0) return "";
    str2.push_back(str1[i]);
    if(i == str1.length() -1) return str2; // Base Case
    if(str1[i] == str1[i+1]) str2.push_back('*');
    return onSecondString(str1,str2,i+1);
}

int main(){
    string str,str2;
    cout << "Enter the input string : " ;
    cin >> str;
    // cout << addStars(str,0);
    cout << onSecondString(str,str2,0);
    return 0;
}