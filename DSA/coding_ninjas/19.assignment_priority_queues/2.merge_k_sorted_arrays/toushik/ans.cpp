//This is a brut approch the tc is 0(nlogn) try to do it in o(nlogk)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
vector<vector<T>> takeInput(){
    int n;
    cin >> n;
    vector<vector<T>> ansVect;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<T> tempVect;
        for(int j = 0; j < k; j++){
            T temp;
            cin >> temp;
            tempVect.push_back(temp);
        }
        ansVect.push_back(tempVect);
    }
    return ansVect;
}

template <typename T>
priority_queue<T,vector<T>,greater<T>> convertInputToQueue(vector<vector<T>>  &input){
    priority_queue<int,vector<int>,greater<int>> ans;

    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[i].size(); j++){
            ans.push(input[i][j]);
        }
    }
    return ans;
}

template <typename T>
void printQueue(priority_queue<T,vector<T>,greater<T>> &inputQueue){
    while(!inputQueue.empty()){
        cout << inputQueue.top() << " ";
        inputQueue.pop();
    }
}

int main(){
    vector<vector<int>> input = takeInput<int>();
    priority_queue<int,vector<int>,greater<int>> inputQueue = convertInputToQueue<int>(input);
    printQueue(inputQueue);
}