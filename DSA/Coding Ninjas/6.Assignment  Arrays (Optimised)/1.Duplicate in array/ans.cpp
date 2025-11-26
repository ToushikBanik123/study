#include <iostream>
#include <vector>
using namespace std;

void takeInput(vector<int> &arr, int n){
    cout << "Entert the elements in the array : ";
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

int main(){
    int n; 
    cout << "Entert the value of (n) : ";
    cin >> n;
    vector<int> arr;
    int map[1000] = {0};
    takeInput(arr,n);
    for(int x : arr){
        map[x]++;
        if(map[x]==2){
            cout << x;
            break;
        }
    }
    return 0;
}