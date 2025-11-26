#include <iostream>
using namespace std;

void takeArrayInput(int *arr, int n){
    cout << "Enter the elements in the array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void printArr(int *arr, int n){
    cout << "This is the content of the array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int countSmallElemetCount(int *arr, int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(arr[0] >= arr[i]){
            count++;
        }
    }
    return count;
}
void quickSortArray(int *arr, int n){
    if(n<=1) return;
    int sec = countSmallElemetCount(arr,n);
    if(sec<=0){
        quickSortArray(arr+1,n-1);
    }else if(sec == n){
        swap(arr[0],arr[n-1]);
        quickSortArray(arr,n-1);
    }else {
        swap(arr[0],arr[sec]);
        int i = 0;
        int j = sec +1;
        while( i < sec && j < n){
            if(arr[sec] <= arr[i] && arr[sec] > arr[j]){
                swap(arr[i], arr[j]);
                i++;
                j++;
            }else if(arr[sec] < arr[j]){
                j++;
            }else{
                i++;
            }
        }
        quickSortArray(arr,sec);
        quickSortArray(arr+sec+1,n-sec-1);
    }
}

int main(){
    int n;
    int arr[100];
    cout << "Enter the length of the array (n) : ";
    cin >> n;
    takeArrayInput(arr,n);
    quickSortArray(arr,n);
    printArr(arr,n);
    return 0;
}