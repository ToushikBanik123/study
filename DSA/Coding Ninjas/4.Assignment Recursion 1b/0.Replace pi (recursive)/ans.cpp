#include <iostream>
#include <string>
using namespace std;

void optimizedInPlace(string &str, int index){
    if(index >= str.length()) return;
    
    if(index + 1 < str.length() && str[index] == 'p' && str[index + 1] == 'i'){
        str.erase(index, 2);
        str.insert(index, "3.14");
        optimizedInPlace(str, index + 4);  // Skip past "3.14" (4 characters)
    } else {
        optimizedInPlace(str, index + 1);
    }
}

int main(){
    string str;
    cout << "Enter the string : ";
    cin >> str;
    
    optimizedInPlace(str, 0);
    cout << str << endl;
    
    return 0;
}