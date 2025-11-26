#include <iostream>
using namespace std;

int recursiveZeroCount(int n){
    if(n == 0) return 0;
    if(n%10 == 0){
        return 1 + recursiveZeroCount(n/10);
    }else{
        return recursiveZeroCount(n/10);
    }
}

int main(){
    int n; 
    cout << "Enter the number : ";
    cin >> n;
    cout << recursiveZeroCount(n);
    return 0;
}