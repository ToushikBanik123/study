#include <iostream>
using namespace std;

bool recurciveElemntFind(int * arr, int n, int x){
    if(n == 0) return false;
    if (n == 1) {
        return arr[0] == x;
    }
    if(arr[0] == x || arr[n-1] == x){
        return true;
    }else{
        return recurciveElemntFind(arr+1, n-2, x);
    } 
}

int main(){
    int arr[100];
    int n,x;
    cout << "Enter the length of the array : ";
    cin >> n;
    cout <<"Enter the elements in the array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to find in the array : " ;
    cin >> x;
    if (recurciveElemntFind(arr, n, x)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}