#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    int sum;
    vector <TreeNode<T> *> child;
    TreeNode(T data){
        this->data = data; 
        this->sum = data;
    }
    
    void addChild(TreeNode<T> * val){
        this->child.push_back(val);
        sum += val->data;
    }

    ~TreeNode(){
        for(int i = 0; i < child.size(); i++){
            delete child[i];
        }
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);
    
    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int childCount;
        cin >> childCount;

        for(int i = 0; i < childCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);
            
            storage.push(childNode);
            curentNode->addChild(childNode);
        }
    }

    return rootNode;
}

template <typename T>
TreeNode<T> * maxNode(TreeNode<T> * rootNode){
    if(rootNode == NULL){
         return rootNode;
    }

    int childNodeMax = 0;
    TreeNode<T> * childMaxNode;

    for(int i = 0; i < rootNode->child.size(); i++){
        TreeNode<T> * maxNodeVal = maxNode<T>(rootNode->child[i]);
        if(maxNodeVal->sum > childNodeMax){
            childNodeMax = maxNodeVal->sum;
            childMaxNode = maxNodeVal;
        }
    }
    if(rootNode->sum > childNodeMax){
        return rootNode;
    }else{
        return childMaxNode;
    }
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    cout << maxNode<int>(rootNode)->data;
    return 0;
}

