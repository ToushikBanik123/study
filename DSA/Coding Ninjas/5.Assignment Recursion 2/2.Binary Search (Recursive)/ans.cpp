#include <iostream>
using namespace std;

void takeArrayInput(int * arr, int n){
    cout << "Enter the arry element : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int binarySearch(int * arr, int s, int e, int t){
    if(e<s) return -1;
    int mid = s + (e-s)/2;
    if(arr[mid] == t) return mid;
    if(t<arr[mid]) return binarySearch(arr,s,mid-1,t);
    return binarySearch(arr,mid+1,e,t);
}

int main(){
    int n;
    int t;
    int arr[100];
    cout << "Enter the length of the array (n) :";
    cin >> n;
    takeArrayInput(arr,n);
    cout << "Enter the t :";
    cin >> t;
    cout << binarySearch(arr,0,n-1,t);
    return 0;
}