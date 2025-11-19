#include <iostream>
#include <string>
using namespace std;

void removeDuplicateInString(string &str, int i = 0){
    // IMPORTANT: Cast str.length() to int before comparison!
    // Reason: str.length() returns size_t (unsigned), and comparing
    // unsigned with (i-1) when i=0 causes -1 to wrap around to a huge
    // positive number (e.g., 4294967295 on 32-bit). This makes the 
    // condition unexpectedly true, breaking logic.
    // Solution: Always cast: if(int(str.length()) < (i-1))
    // Or better: if(i >= str.length() - 1) return;
    if(i >= str.length() - 1) return;
    if(str[i] == str[i+1]){
        //remove the element 
        str.erase(i,1);
        //call on the same i as the string is reduced by 1 no no need to do +1
        return removeDuplicateInString(str,i);
    }
    //call it on the next index
    return removeDuplicateInString(str,(i+1));
}

int main(){
    string str;
    cout << "Enter you string : ";
    cin >> str;
    removeDuplicateInString(str);
    cout << str;
    return 0;
}