#include <iostream>
using namespace std;

int strSubSequence(string inputStr, string * outputStr){
    if(inputStr.empty()){
        outputStr[0] = "";
        return 1;
    }
    int se = strSubSequence(inputStr.substr(1),outputStr);
    for(int i = 0; i < se; i++){
        outputStr[se+i] = outputStr[i] + inputStr[0];
    }
    return 2* se;
}

int main(){
    string inputStr; 
    cout << "Enter the string : ";
    cin >> inputStr;
    string * outputStr = new string[pow(2,inputStr.length())];
    int outputStrLen = strSubSequence(inputStr,outputStr);
    for(int i = 0; i < outputStrLen; i++){
        cout << outputStr[i] << endl;
    }
    return 0;
}