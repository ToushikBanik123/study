#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
vector<T> takeVectorInput(){
    vector<T> ansVector;
    while(true){
        T data;
        cin >> data;
        if(data == -1) return ansVector;
        ansVector.push_back(data);
    }
}

template <typename T>
int pairCount(vector<T> & inputData){
    unordered_map<T,int> storage;

    for(int i = 0; i < inputData.size(); i++){
        if(storage.count(inputData[i]) < 1){
            storage[inputData[i]] = 1;
        }
    }

    int count = 0;

    for(int i = 0; i < inputData.size(); i++){
        if(0 < storage.count(0 - inputData[i])){
            count++;
        }
    }
    return count/2;
}

int main(){
    vector<int> inputData = takeVectorInput<int>();
    cout << pairCount<int>(inputData);
    return 0;
}