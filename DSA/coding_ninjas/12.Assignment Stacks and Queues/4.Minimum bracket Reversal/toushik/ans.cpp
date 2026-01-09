#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printStack(stack<char> storage){
    while(!storage.empty()){
        cout << storage.top();
        storage.pop();
    }
}

stack<char> removeAllTheBalancedOne(string &str){
    stack<char> storage;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '}' && !storage.empty() && storage.top() == '{'){
            storage.pop();
            continue;
        }
        storage.push(str[i]);
    }
    return storage;
}

template <typename T>
int findRequareCount(stack<T> storage){
    int count = 0;
    while(!storage.empty()){
        if(storage.top() == '{'){
            storage.pop();
            if(storage.empty()) return -1;
            if(storage.top() == '{'){
                count++;
            }else{
                count += 2;              
            }
            storage.pop();
        }else{
            storage.pop();
            if(storage.empty()) return -1;
                if(storage.top() == '{'){
                count+=2;               
            }else{
                count++;
            }
            storage.pop();
        }
    }
    return count;
}

int main(){
    string str;
    cout << "Enter the value of your string  : ";
    cin >> str;
    if(str.length()%2 != 0){
        cout << -1;
    }else{
        stack<char> storage = removeAllTheBalancedOne(str);
        cout << findRequareCount(storage);
    }
    return 0;
}