#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> data){
    while(!data.empty()){
        cout << data.front() << " ";
        data.pop();
    }
    cout << endl;
}

void takeQueueInput(queue<int> &data){
    int i;
    while(true){
        cin >> i;
        if(i == -1) return;
        data.push(i);
    }
}

void revartTheQueue(queue<int> &data){
    if(data.empty()) return;
    int val = data.front();
    data.pop();
    revartTheQueue(data);
    data.push(val);
}

int main(){
    queue <int> data;
    takeQueueInput(data);
    printQueue(data);
    revartTheQueue(data);
    printQueue(data);
    return 0;
}
