#include <iostream>
using namespace std;

int recursivePower(int x, int n){
    if(n == 0) return 1;
    return x * recursivePower(x,--n);
}

int main(){
    int x, n; 
    cin >> x >> n; 
    int ans = recursivePower(x,n);
    cout << ans << endl;
    return 0;
}