#include <iostream>
using namespace std;

int recursiveDigitCount(int n){
    if(n == 0) return 0;
    return 1 + recursiveDigitCount(n/10);
}

int main(){
    int number; 
    cout << "Enter the Number : ";
    cin >> number;
    if(number == 0){
        cout << "1"<< endl;
    }
    cout << recursiveDigitCount(number);
    return 0;
}