#include<iostream>
#include <climits>
using namespace std;

int findMin(int n){
    if(n == 1) return 0;

    int ans = 1;

    int step_1 = findMin(n-1);
    int step_2 = INT_MAX;
    int step_3 = INT_MAX;

    if(n%2 == 0){
        step_2 = findMin(n/2);
    }
    if(n%3 == 0){
        step_3 = findMin(n/3);
    } 

    ans += min(step_1,min(step_2,step_3));
    return ans;
}

int findMinGridy(int n){
    int i = 1;
    int count = 0;
    while(i<n){
        if(i*3 <= n){
            i *= 3;
            count++;
        }else if(i*2 <=n){
            i *= 2;
            count++;
        }else{
            i++;
            count++;
        }
    }
    return count;
}

int findMinMemory(int n, int * arr){
    if(n == 1) return 0;
    if(arr[n] != -1) return arr[n];

    int ans = 1;

    int step_1 = findMinMemory(n-1);
    int step_2 = INT_MAX;
    int step_3 = INT_MAX;

    if(n%2 == 0){
        step_2 = findMinMemory(n/2);
    }
    if(n%3 == 0){
        step_3 = findMinMemory(n/3);
    } 

    ans += min(step_1,min(step_2,step_3));
    arr[n] = ans;
    return ans;
}

int findMinDp(int n, int * arr){
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i <= n; i++){
        int x = arr[i-1];
        int y = INT_MAX;
        int z = INT_MAX;

        if(i%2 == 0){
            y = arr[i/2];
        }
        if(i%3 == 0){
            z = arr[i/3];
        }
        arr[i] = 1 + min(x,min(y,z));
    }
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n+1; i++){
        arr[i] = -1;
    }

    cout << "The min number of steps requared are : " << findMinDp(n,arr) << endl;
    return 0;
}