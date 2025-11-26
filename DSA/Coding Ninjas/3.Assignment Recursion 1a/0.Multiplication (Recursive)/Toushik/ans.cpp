#include <iostream>
using namespace std;

int recursiveMultiple(int n, int m){
    if( n == 0 || m == 0) return 0;
    return n + recursiveMultiple(n, m - 1);
}

int main(){
    int n, m; 
    cout << "Ente the vale of N : ";
    cin >> n;
    cout << "Enter the value of M : ";
    cin >> m;
    cout << " Your Recursive Multiple is : " << recursiveMultiple(n,m) << endl;
    return 0;
}