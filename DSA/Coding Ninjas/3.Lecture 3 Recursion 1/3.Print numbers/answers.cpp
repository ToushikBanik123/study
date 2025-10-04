#include <iostream> 
using namespace std;

void recursivePrint(int n){
    if(n == 0) return;
    recursivePrint(n - 1);
    cout << n << " ";
}

int main(){
    int n; 
    cout << "Enter the value of n : ";
    cin >> n; 
    recursivePrint(n);
    return 0;
}