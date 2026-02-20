#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> takeVectorInput(){
    vector<T> ans; 
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++){
        T data;
        cin >> data;
        ans.push_back(data);
    }
    return ans;
}
                                                                               
int main(){
    vector<int> inputVect = takeVectorInput<int>();
    if(inputVect.size() == 0) return 0;

    unordered_set<int> inputSet = vectorToSet<int>(inputVect);
    int maxLength = -1;
    pair<int,int> output = {-1,-1};
    for(int i = 0; i < inputVect.size(); i++){
        if(lowerIndexAvailable(inputVect[i],inputSet)){
            continue;
        }
        int si = inputVect[i];
        int ei = findTheEnd(si,inputSet);
        if(maxLength < (ei-si)){
            maxLength = (ei-si);
            output.first = si;
            output.second = ei;
        }
    }   
    if(output.first == -1){
        cout << inputVect[0] << endl;
    }else{
        cout << output.first << " " << output.second << endl;
    }
    return 0;
}