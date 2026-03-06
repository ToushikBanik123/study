#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
vector<T> takeInputVect(int n){
    vector<T> ansVect;
    for(int i = 0; i < n; i++){
        T temp;
        cin >> temp;
        ansVect.push_back(temp);
    }
    return ansVect;
}

template <typename T>
unordered_map<T,T> vectToMap(vector<T> &inputVect){
    unordered_map<T,T> ansMap;
    for(int i = 0; i < inputVect.size(); i++){
        ansMap[inputVect[i]]++;
    }
    return ansMap;
}

template <typename T>
int findPairCount(unordered_map<T,T> &inputMap, vector<T> &inputVect, T k){
    int count = 0;
    for(int i = 0; i < inputVect.size(); i++){
        if(inputMap.find(inputVect[i] + k) != inputMap.end()){
            inputMap[inputVect[i]]--;
            count += inputMap.find(inputVect[i] + k)->second;
        }
    }
    return count;
}

int main(){
    int n; 
    int k;
    
    cin >> n;
    vector<int> inputVect = takeInputVect<int>(n);
    cin >> k;
    
    unordered_map<int,int> inputMap = vectToMap<int>(inputVect);
    int count = findPairCount<int>(inputMap,inputVect,k);
    cout << count << endl;
}
