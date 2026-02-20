 #include <iostream>
 #include <queue>
 #include <vector>
 using namespace std;
 
template <typename T>
vector<T> takeinput(){
    vector<T> input;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        T temp;
        cin >> temp;
        input.push_back(temp);
    }
    return input;
}

template <typename T>
void printVector(vector<T> &input){
    for(int i = 0; i < (int)input.size(); i++){
        cout << input[i] << " ";
    }
}

template<typename T>
priority_queue<int,vector<int>,greater<int>> pqFromArray(vector<int> & input, int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }
    for(int i = k; i < input.size(); i++){
        if(pq.top() < input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }
    return pq;
}

template <typename T>
vector<T> pqToVector(priority_queue<int,vector<int>,greater<int>> pq){
    vector<T> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> input = takeinput<int>();
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> pq = pqFromArray<int>(input,k);
    vector<int> ans = pqToVector<int>(pq);
    printVector<int>(ans);
    return 0;
}