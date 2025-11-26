#include <iostream>
using namespace std;

int recursiveSum(int *arr, int n){
    if(n == 0 ) return arr[0];
    return arr[n] + recursiveSum(arr, n - 1);
}

int main(){
    int arr[100];
    int n; 
    cout << "ENter the size of your array : ";
    cin >> n;
    if(n <= 0) return 0; 
    cout << "Enter your elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << recursiveSum(arr,n-1);
    return 0;
}