#include <iostream>
using namespace std;

void takeArrayInput(int * arr, int n){
    cout << "Eter all the elements of your array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];   
    }
}
void printArray(int *arr, int n){
    cout << "Printed Array :  ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";   
    }
}

void mergeSortedArray(int* arr1, int* arr2, int n1, int n2, int* arrf){
    int j = 0; 
    int k = 0;
    int nf = n1 + n2;
    for(int i = 0; i < nf; i++){
        if(n1 <= j){
            arrf[i] = arr2[k];
            k++;
        }else if(n2 <= k){
            arrf[i] = arr1[j];
            j++;
        }else if(arr1[j] <= arr2[k]){
            arrf[i] = arr1[j];
            j++;
        }else{
            arrf[i] = arr2[k];
            k++;
        }
    }   
}

void copyArr(int * arr1, int * arr2, int n){
    for(int i = 0; i < n ; i++){
        arr2[i] = arr1[i];
    }
}

void mergeSort(int * arr, int n){
    if(n<=1) return;
    int arrf[100];
    int mid = n/2;
    mergeSort(arr,mid);
    mergeSort((arr+mid),(n-mid));
    mergeSortedArray(arr,(arr+mid),mid,(n-mid),arrf);
    copyArr(arrf,arr,n);
}

int main(){
    int n;
    int arr[100];
    cout << "Enter the length of the array (n) : ";
    cin >> n;
    takeArrayInput(arr,n);
    mergeSort(arr,n);
    printArray(arr,n);
    return 0;
}