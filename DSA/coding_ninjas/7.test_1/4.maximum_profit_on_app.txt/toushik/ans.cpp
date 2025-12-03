#include <iostream>
#include <vector>
using namespace std;

void takeArrayInput(vector<int> &arr, int n){
    cout << "Enter the elements of the array : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
}

int merge(vector<int> &arr, int s1, int mid, int n){
    vector<int> temp;
    int max = INT_MIN;
    for(int i = 0; i < n; i ++){
        if(mid <= s1){
            temp[i] = arr[s2];
            s2++;
        }else if(n <= s2){
            temp[i] = arr[s1];
            s1++;
        }else if(arr[s1] < arr[s2]){
            temp[i] = arr[s1];
            s1++;
        }else{
            temp[i] = arr[s2];
            s2++;
        }
        if(max < = (temp[i]*(n-i))){
            max = (temp[i]*(n-i));
        }
    }
}

void Sort(vector<int> &arr, int s, int e){
    if(e<=s) return;
    int mid = s + (e-s)/2;
    Sort(arr, s, mid);
    Sort(arr,mid+1, e);
    cout << merge(arr,s,mid+1,)
    
}

int main(){
    int n;
    vector<int> arr;
    cout << "Enter the value of (n) : ";
    cin >>n;
    takeArrayInput(arr,n);
    return 0;
}