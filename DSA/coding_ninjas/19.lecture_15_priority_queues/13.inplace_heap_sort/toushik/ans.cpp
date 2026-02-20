#include <iostream>
#include <vector>
using namespace std;

int leftChild(int i){
    return (2 * i) + 1;
}

int rightChild(int i){
    return (2 * i) + 2;
}

int parent(int i){
    return (i - 1) / 2;
}

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

template <typename T>
void createmaxheap(vector<T> &input){
    int hps = 0;
    while(hps < (int)input.size()){
        hps++;
        int i = hps - 1;
        while(i > 0){
            int p = parent(i);
            if(input[p] < input[i]){
                swap(input[p], input[i]);
                i = p;
            } else {
                break;
            }
        }
    }
}

template <typename T>
void downHeapify(vector<T> &input, int hps){  // Fix 1: vector<T> not vector<int>
    int i = 0;
    while(i < hps){                           // Fix 2: was (hps < i), never executed
        int l = leftChild(i);
        int r = rightChild(i);
        int mi = i;

        if(l > hps){                          // left child out of bounds
            break;
        }
        if(input[mi] < input[l]){
            mi = l;
        }
        if(r <= hps && input[mi] < input[r]){ // Fix 3: was (r < hps), missed last element
            mi = r;
        }

        if(mi == i) break;
        swap(input[mi], input[i]);
        i = mi;
    }
}

template <typename T>
void sortArray(vector<T> &input, int hps){    // Fix 4: vector<T> not vector<int>
    if(hps == 0) return;
    swap(input[0], input[hps]);
    hps--;
    downHeapify<T>(input, hps);
    sortArray<T>(input, hps);
}

int main(){
    vector<int> input = takeinput<int>();
    createmaxheap<int>(input);
    sortArray<int>(input, (int)(input.size() - 1));
    printVector<int>(input);
    return 0;
}