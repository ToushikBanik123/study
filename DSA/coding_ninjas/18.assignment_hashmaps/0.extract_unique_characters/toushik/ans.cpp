#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void processString(string &s){
    unordered_set<int> storage;
    for(int i = 0; i < s.size(); i++){
        if(storage.count(s[i])){
            s.erase(i, 1);
            i--;
        }else{
            storage.insert(s[i]);
        }
    }
}

int main(){
    string s;
    cin >> s;
    processString(s);
    cout << s;
    return 0;
}