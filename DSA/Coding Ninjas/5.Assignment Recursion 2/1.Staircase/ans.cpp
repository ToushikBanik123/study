#include <iostream>
using namespace std;

int f(int n,int count = 0){
    if(n < count) return 0;
    if(n == count) return 1;
    return f(n,count+1)+f(n,count+2)+f(n,count+3);
}

void fs(int sum, int &count, int n){
    if(sum == n){
        count++;
        return;
    }
    for(int i = 1; i <= 3; i++){
        if(sum + i > n) break;
        fs(sum+i,count,n);
    }
}

int fsb(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    // if(n== 1) return 1;
    // if(n==2) return 2;
    return fsb(n-1) + fsb(n-2) + fsb(n-3);
}

int main(){
    int n;
    int count= 0;
    cout << "Enter the value of the n : ";
    cin >> n;
    cout << fsb(n);
    // fs(0,count,n);
    // cout << count;
    return 0;
}