#include <iostream>
using namespace std; 

void subSequence(int n,string * keypad,string output = ""){
    if(n == 0){
        cout << output << endl;
    }
    int temp = n%10;
    n = n/10;
    for(int i = 0;i < keypad[temp].size(); i++){
        subSequence(n,keypad,keypad[temp][i]+output);
    }
}

int main(){
    int n;
    string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    cout << "Enter the number (n) : ";
    cin >> n;
    subSequence(n,keypad);
    return 0;
}