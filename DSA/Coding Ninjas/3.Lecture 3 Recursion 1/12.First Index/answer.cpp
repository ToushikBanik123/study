#include <iostream>
using namespace std;

int recurciveElementFind(int * arr, int i, int n, int x){
    if(i == n) return -1;
    if(arr[i] == x) return i;
    return recurciveElementFind(arr, i + 1, n, x);
}

int main(){
    int x,n;
    int arr[200];
    cout << "Enter the length of the array : ";
    cin >> n;
    cout << " Enter all the elements in the array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to find(X) : ";
    cin >> x;
    cout << recurciveElementFind(arr,0,n,x);
    return 0;
}