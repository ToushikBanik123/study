#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> takeInput(){
    vector<T> ans;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        T temp;
        cin >> temp;
        ans.push_back(temp);
    }
    return ans;
}

int leftChild(int i){
    return (2*i) + 1;
}

int rightChild(int i){
    return (2 * i) + 2;
}

template <typename T>
bool validateIndex(vector<T> & input, int i){
    int l = leftChild(i);
    int r = rightChild(i);
    int size = input.size();

    if(l < size && input[i] < input[l]){
        return 0;
    }
    if(r < size && input[i] < input[r]){
        return 0;
    }
    return 1;
}

template <typename T>
bool validateArray(vector<T> &input){
    for(int i = 0; i < (input.size()/2)-2; i++){
        if(!validateIndex<T>(input,i)){
            return 0;
        }
    }
    return 1;
}

int main(){
    vector<int> input = takeInput<int>();
    bool ans = validateArray<int>(input);
    if(ans){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}