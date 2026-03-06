#include <iostream>
#include <queue>
using namespace std;

template <typename T>
T findMedian(T val,priority_queue<T,vector<T>,greater<T>> &minq,priority_queue<T> &maxq){
    //1st element 
    if(maxq.size() == 0){
        maxq.push(val);
        return val;
    }

    //value insertion
    if(val < maxq.top()){
        maxq.push(val);
    }else{
        minq.push(val);
    }

    //balancing 
    if(max(maxq.size(),minq.size()) - min(maxq.size(),minq.size()) > 1){
        if(maxq.size() > minq.size()){
            minq.push(maxq.top());
            maxq.pop();
        }else{
            maxq.push(minq.top());
            minq.pop();
        }
    }

    if(maxq.size() > minq.size()){
        return maxq.top();
    }else if(minq.size() > maxq.size()){
        return minq.top();
    }else{
        return (maxq.top()+minq.top())/2;
    }
}

int main(){
    int n; 
    cin >> n;

    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cout << findMedian<int>(temp,minq,maxq);
    }
    return 0;
}