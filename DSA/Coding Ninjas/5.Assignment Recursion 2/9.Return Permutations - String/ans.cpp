#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<string> &ans){
    for(string s : ans){
        cout << s << endl;
    }
}

void allPermutation(string s,vector<string> &ans){
    if(s.size() == 1){
        ans.push_back(s);
        return;
    }
    allPermutation(s.substr(1),ans);
    vector<string> temp;
    for(int i = 0; i <= ans[0].length(); i++){
        for(string x : ans){
            temp.push_back(x.insert(i,1,s[0]));
        }
    }
    ans = temp;
}

int main(){
    string s;
    vector <string> ans;
    cout <<"Enter the value of the string (s) : ";
    cin >> s;
    allPermutation(s,ans);
    printVector(ans);
}
