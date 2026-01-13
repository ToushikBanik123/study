#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public: 
    T data;
    vector <TreeNode<T>*> child;

    TreeNode(T data){
        this->data = data;
    }
}; 

template <typename T>
TreeNode<T> * takeTreeInpur(){
    T rootNodeData; 
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int curentNodeChildCount; 
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i++){
            T childNodeData; 
            cin >> childNodeData;

            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);

            curentNode->child.push_back(childNode);
            storage.push(childNode);
        }
    }

    return rootNode;
}

template <typename T>
int leafCount(TreeNode<T> * rootNode){
    if(rootNode == NULL) return 0;
    if(rootNode->child.size() == 0) return 1;
    int childNodeCount = 0;
    for(int i = 0; i < rootNode->child.size(); i++){
        childNodeCount += leafCount(rootNode->child[i]);
    }
    return childNodeCount;
}

int main(){
    TreeNode<int>* rootNode = takeTreeInpur<int>();
    cout << leafCount<int>(rootNode);
    return 0;
}