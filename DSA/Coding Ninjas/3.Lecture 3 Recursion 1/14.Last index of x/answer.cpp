#include <iostream>
using namespace std;

int recurciveElmentFind(int * arr, int n, int x){
    if(n == 0) return -1;
    int i = n-1;
    if(arr[i] == x) return i;
    return recurciveElmentFind(arr, n -1, x);
}

int main(){
    int x,n;
    int arr[100];
    cout << "Enter the lenght of the array(n) : ";
    cin >> n;
    cout << "Enter the elements in the array arr[??] : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to find in the array (X) : ";
    cin >> x;
    cout << recurciveElmentFind(arr,n,x);
    return 0;
}