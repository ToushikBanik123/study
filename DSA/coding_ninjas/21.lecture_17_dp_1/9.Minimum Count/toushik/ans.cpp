#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int f(int n , unordered_map<int,int> & map){
    if(n == 0) return 0;
    if (n == 1) return 1;
    if(map.find(n) != map.end()) return map.at(n);

    int minVal = INT_MAX;
    int i = 1;
    while(i*i <= n){
        minVal = min(minVal,f(n-i*i, map));
        i++;
    }
    map[n] = 1 + minVal;
    return 1+ minVal;
}

int main(){
    int n; 
    cin >> n;
    unordered_map<int,int> map;
    cout << f(n,map);
    return 0;
}