#include <iostream>
#include <stack>
using namespace std; 

bool ifStartingBrackets(char c){
    if(c == '(' || c == '[' || c == '{'){
        return true;
    }else{
        return false;
    }
}


bool ifEndingBrackets(char c){
    if(c == ')' || c == ']' || c == '}'){
        return true;
    }else{
        return false;
    }
}

char revartChar(char c){
    if(c == '('){
        return ')';
    }else if(c == '{'){
        return '}';
    }else if(c == '['){
        return ']';
    }else{
        return '0';
    }
}

bool equationCheck(string s){
    stack<char> equationCheckStack;
    for(auto i : s){
        if(ifStartingBrackets(i)){
            equationCheckStack.push(i);
        }
        else if(ifEndingBrackets(i)){
            if(revartChar(equationCheckStack.top()) != i) return false;
            equationCheckStack.pop();
        }
    }
    if(equationCheckStack.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s; 
    cout << "Enter the value of your expretion/string (s) : ";
    cin >> s; 
    cout << equationCheck(s);
}