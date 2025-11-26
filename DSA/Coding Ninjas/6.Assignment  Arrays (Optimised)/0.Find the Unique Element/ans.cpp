#include <iostream>
#include <vector>
using namespace std;

void takeInput(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

int findElement(vector<int> elements, int i = 0){
    if(i >= elements.size() - 1){
        return elements[i];
    }
    return elements[i] ^ findElement(elements, i + 1);
}

int main(){
    int k; 
    cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        cin >> n;  // Read n before using it
        vector<int> elements;
        takeInput(elements, n);
        cout << findElement(elements) << endl;  // Output the result
    }
    return 0;
}
