#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
vector<T> inputVect(){
    int n;
    cin >> n;
    vector<T> ans;

    for(int i = 0; i < n; i++){
        T temp; 
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

int findMaxLength(vector<int> & input){
    int maxLength = -1;
    unordered_map<int,int> unMap;
    int sum = 0;
    for(int i = 0; i < input.size(); i++){
        sum += input[i];
        if(unMap.find(sum) != unMap.end()){
            //find the value 
            int diff = i - unMap[sum];
            if(maxLength < diff){
                maxLength = diff;
            }
        }else{
            unMap[sum] = i;
        }
    }
    return maxLength;
}

int main(){
    vector<int> input = inputVect<int>();
    cout << findMaxLength(input);
    return 0;
}