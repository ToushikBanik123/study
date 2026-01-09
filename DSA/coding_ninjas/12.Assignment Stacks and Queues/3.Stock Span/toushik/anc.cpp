#include <iostream>
#include <stack>
using namespace std;

int takeArrayInput(int * arr){
    int n;
    cout << "Enter the element count(n) : ";
    cin >> n;
    cout << "Enter the your array now : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    return n;
}

void printTheArray(int * arr, int &n){
    cout << "The value of your array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findTheSpan(stack<int> stack){
    int k = stack.top();
    int count = 1;
    stack.pop();
    //always check if it is empty or not.
    while(!stack.empty() && stack.top() < k){
        count++;
        stack.pop();
    }
    return count;
}

void creatSpanArray(int * arr, int *answerArray, int n){
    stack<int> storage;
    for(int i = 0; i < n; i++){
        storage.push(arr[i]);
        answerArray[i] = findTheSpan(storage);
    }
}

int main(){
    int arr[100];
    int answerArray[100];
    int n = takeArrayInput(arr);
    printTheArray(arr,n);
    creatSpanArray(arr,answerArray,n);
    printTheArray(answerArray,n);
    return 0;
}