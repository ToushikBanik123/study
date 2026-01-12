#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int popCount(stack<char> &storage){
    int count = 0;
    while(storage.top() != '('){
        count++;
        storage.pop();
    }
    storage.pop();
    return count;
}

bool evaluateTheExperation(string s){
    stack<char> storage;
    int count = 0;
    int i = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ')'){
            int count = popCount(storage);
            if(count == 0){
                return true;
            }
            continue;
        }
        storage.push(s[i]);
    }
    return false;
}

int main(){
    string s;
    cout << "Enter the value of the String s : ";
    cin >> s;
    if(evaluateTheExperation(s)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}