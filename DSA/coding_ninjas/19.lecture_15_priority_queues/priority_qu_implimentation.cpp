#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue{
    vector<T> pq;

    //For finding the parent of the index
    int parent(int i){
        if(i == 0) return 0;
        return (i -1)/2;
    }
    //get the left child index
    int leftChild(int i){
        return (2 * i) + 1;
    }
    //get the right child index
    int rightChild(int i){
        return (2 * i) + 2;
    }

    //Shift the elemt to The top
    void upShift(int i){ 
        int p = parent(i);
        while(0 < i){
            if(pq[i] < pq[p]){
                swap(pq[i],pq[p]);
                i = p;
                p = parent(i);
            }else{
                break;
            }
        }
    }

    //Shift the element to the botom until place is found
    void downShift(int i){
        int l = leftChild(i);
        int r = rightChild(i);

        int minIndex = i;

        //breaking condition + check l < size() in one instant.
        if(size() <= l) return;

        if(pq[l] < pq[minIndex]){
            minIndex = l;
        }

        if(r < size() && pq[r] < pq[minIndex]){
            minIndex = r;
        }

        if(minIndex == i) return;
        swap(pq[i], pq[minIndex]);
        downShift(minIndex);
    }

    public:
    int size(){
        return pq.size();
    }

    bool empty(){
        if(size() == 0){
            return 1;
        }else{
            return 0;
        }
    }

    void push(T data){
        pq.push_back(data);
        upShift(size() -1);
    }

    T top(){
        if(size() == 0) throw runtime_error("Queue is empty");
        return pq[0];
    }

    void pop(){
        if(size() == 0) return 0;
        pq[0] = pq[size()-1];
        pq.pop();
        downShift(0);
    }

};


int main(){
    return 0;
}