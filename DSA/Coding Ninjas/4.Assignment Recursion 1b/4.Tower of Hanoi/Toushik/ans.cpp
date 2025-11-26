#include <iostream>
using namespace std;

void towerOfHannoi(int n, char source, char destination, char auxiliary){
    if(n==0) return;
    towerOfHannoi(n-1,source,auxiliary,destination);
    cout << "Move : " << n << " -> " << source << " to " << destination << endl;
    towerOfHannoi(n-1,auxiliary,destination,source);
} 

int main(){
    int n;
    cout << "Enter the value of n : " ;
    cin >> n;
    towerOfHannoi(n,'A','C','B');
    return 0;
}