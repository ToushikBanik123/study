#include <iostream>
#include <unordered_map>
using namespace std;

int countPossibleWaysMemorization(int n, unordered_map<int,int> &map){
    if(n < 0) return 0;
    if(map.find(n) != map.end()){
        return map[n];
    }

    int ans = countPossibleWaysMemorization(n-1,map) 
    + countPossibleWaysMemorization(n-2,map) 
    + countPossibleWaysMemorization(n-3,map);
    map[n] = ans;
    return ans;
}

void countPossibleWaysTabulaation(int n, unordered_map<int,int> &map){
    map[0] = 1;
    for(int i = 1; i <= n; i++){
        map[i] = map[i-1] +  map[i-2] + map[i-3];
    }
}

int main(){
    int n;
    cin >> n;

    unordered_map<int,int> map;
    map[0] = 1;
    // cout << countPossibleWaysMemorization(n,map) << endl;
    countPossibleWaysTabulaation(n,map);
    cout << map[n] << endl;
}