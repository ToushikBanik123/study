#include <iostream>
#include <stack>
using namespace std;

//to print the value of the stack
void printStack(stack<int> &st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

//to take inputo of the stack 
void takeInputInTheStack(stack<int> &st){
    int i; 
    while(true){
        cin >> i;
        if(i == -1) return; 
        st.push(i);
    }
}

//revart the stack in the extra stack. with recusive stack 
void revartStack(stack <int> &st, stack<int> &temp){
    if(st.empty()) return;
    int top = st.top();
    st.pop();
    revartStack(st,temp);
    temp.push(top);
}

//coppy the value back in the main stack 
void coppyBack(stack <int> &st, stack<int> &temp){
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> st;
    stack<int> temp;
    takeInputInTheStack(st);
    // printStack(st);
    revartStack(st,temp);
    coppyBack(st,temp);
    cout << "Printing the temp : ";
    printStack(st);
    return 0;
}