#include<iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> child;

    TreeNode(T data){
        this->data = data;
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    queue<TreeNode<T> *> storage;
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);
    storage.push(rootNode);

    while(!storage.empty()){
        int curentNodeChildCount;
        TreeNode<T> * curentNode = storage.front();

        storage.pop();
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i ++){
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
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T>*> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T>* curentNode = storage.front();
        storage.pop();

        cout << curentNode->data << ":";
        for(int i = 0; i < curentNode->child.size(); i++){
            cout<<curentNode->child[i]->data << ",";
            storage.push(curentNode->child[i]);
        }
        cout << endl;
    }
}

template <typename T>
TreeNode<T> * findLargestNode(TreeNode<T> * rootNode){
    TreeNode<T> * largestNode = rootNode;
    for(int i = 0; i < rootNode->child.size(); i++){
        TreeNode<T> * curentNodesLargestNode = findLargestNode<T>(rootNode->child[i]);
        if(curentNodesLargestNode->data > largestNode->data){
            largestNode = curentNodesLargestNode;
        }

    }
    return largestNode;
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    printTree<int>(rootNode);
    cout << "Largest Data : " << findLargestNode<int>(rootNode)->data << endl;
    return 0;
}