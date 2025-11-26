#include <iostream>
using namespace std;

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void getArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void f(int *arr, int n, int i, int ans[], int j){
    // Base case: when we've processed all elements
    if(i == n){
        printArr(ans, j);
        return;
    }
    
    // Include current element
    ans[j] = arr[i];
    f(arr, n, i+1, ans, j+1);
    
    // Exclude current element
    f(arr, n, i+1, ans, j);
}

int main(){
    int arr[100];
    int ans[100];
    int n;
    cout << "Enter the length of the array (n) : ";
    cin >> n;
    getArray(arr, n);
    f(arr, n, 0, ans, 0);

    return 0;
}
