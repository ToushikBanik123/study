#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

template <typename T>
vector<T> takeVectorInpur(){
    int count; 
    cin >> count;
    vector<T> answerVector;

    for(int i = 0; i < count; i++){
        T input;
        cin >> input;
        answerVector.push_back(input);
    }

    return answerVector;
}

template <typename T>
unordered_map<T,bool> vectorToMap(vector<T> &input1){
    unordered_map<T,bool> inputMap;
    for(int i = 0; i < input1.size(); i++){
        inputMap[input1[i]] = 1;
    }
    return inputMap;
}

template <typename T>
void printIntersection(vector<T> &input1, vector<T> &input2){
    unordered_map<T,bool> inputMap = vectorToMap<T>(input1);
    for(int i = 0; i < input2.size(); i++){
        if(0 < inputMap.count(input2[i])){
            cout << input2[i] << " ";
        }
    }
}

int main(){
    vector<int> input1 = takeVectorInpur<int>();
    vector<int> input2 = takeVectorInpur<int>();

    printIntersection<int>(input1,input2);
    return 0;
}