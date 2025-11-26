#include <iostream>
#include <vector>
using namespace std;

void takeArrayInput(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

int main(){
    vector<int> arr1,arr2;
    int map[1000] = {0};
    int m,n;
    cout <<"Enter the value of m : ";
    cin >> m;
    takeArrayInput(arr1,m);
    cout <<"Enter the value of n : ";
    cin >> n;
    takeArrayInput(arr2,n);
    for(int x : arr1){
        map[x]++;
    }
    for(int x : arr2){
        if(map[x]>0){
            cout << x << " ";
            map[x]--;
        }
    }
}