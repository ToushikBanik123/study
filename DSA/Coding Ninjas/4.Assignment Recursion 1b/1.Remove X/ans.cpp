#include <iostream>
#include <string>
using namespace std;

string removeX(string str, int i){
    if(str.length() <= i) return str;
    if(str[i] == 'x'){
        str.erase(i,1);
        return removeX(str,i);
    }
    return removeX(str,i+1);
}

int main(){
    string str;
    cout << "Enter the string : ";
    cin >> str;
    cout << removeX(str,0);
    return 0;
}