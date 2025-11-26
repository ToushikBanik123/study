#include <iostream>
using namespace std;

int subSequence(int n, string * output, string * keybordStrings){
    if(n == 0){
        output[0] = "";
        return 1;
    }
    int k = n%10;
    string ks = keybordStrings[k];
    int subSequenceLength = subSequence(n/10,output,keybordStrings);
    int count = 0;
    string * tempString = new string[1000];
    for(int i = 0; i < ks.size(); i++){
        for(int j = 0; j < subSequenceLength; j++){
            tempString[count] = ks[i] + output[j];
            count++;
        }
    }
    for(int i = 0; i <= count; i++){
        output[i] = tempString[i];
    }
    return (ks.size()*subSequenceLength);
}

int main(){
    string keybordStrings[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string * output = new string[10000];
    int n; 
    cout << "Enter the number value (n) : ";
    cin >> n;
    int outputLength = subSequence(n,output,keybordStrings);
    for(int i = 0; i < outputLength; i ++){
        cout << output[i] << endl; 
    }
}