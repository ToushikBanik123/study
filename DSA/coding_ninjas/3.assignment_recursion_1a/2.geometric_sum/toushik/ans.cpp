#include <iostream>
using namespace std;

double recursiveGeometricSum(int k){
    if(k == 0) return 1.0;
    return (1.0/pow(2,k)) + recursiveGeometricSum(k-1); 
}

int main(){
    int k;
    cout << "Enter the vaue of K : ";
    cin >> k;
    cout << recursiveGeometricSum(k) << endl;
    return 0;
}

