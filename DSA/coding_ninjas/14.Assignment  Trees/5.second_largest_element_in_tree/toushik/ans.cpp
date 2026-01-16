#include <iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode<T> *> child;
    TreeNode(T data){
        this->data = data;
    }
};

template <typename T>
class Highest{
    public:
    T highest;
    T secondHighest;
    Highest(T data){
        this->highest = data;
        this->secondHighest = 0;
    }
    void updateWithVal(T data){
        if(data > this->highest){
            this->secondHighest = this->highest;
            this->highest = data;
        }else if(data > this->secondHighest && data < this->highest){
            this->secondHighest = data;
        }
    }

    void hupdateWithNode(Highest<T> &h){
        updateWithVal(h.highest);
        updateWithVal(h.secondHighest);
    }

};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);

    queue<TreeNode<T> *> q;
    q.push(rootNode);

    while(!q.empty()){
        TreeNode<T> * curentNode = q.front();
        q.pop();
        int curentNodeChildCount;
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);

            q.push(childNode);
            curentNode->child.push_back(childNode);
        }
    }
    return rootNode;
}

template <typename T>
    Highest<T> findTheSecorLargest(TreeNode<T> * rootNode){
    Highest<T> h = Highest<T>(rootNode->data);

    for(int i = 0; i < rootNode->child.size(); i++){
        Highest<T> childh = findTheSecorLargest<T>(rootNode->child[i]);
        h.hupdateWithNode(childh);
    }
    return h;
}


int main(){
    cout << "Enter the Tree Value : ";
    TreeNode<int> * rootNode = takeInput<int>();
    cout << findTheSecorLargest<int>(rootNode).secondHighest;
    return 0;
}