#include <iostream>
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
TreeNode<T> * takeTreeInput(){
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
        for(int i = 0 ; i < curentNodeChildCount; i++){
            T childData;
            cin>>childData;
            TreeNode<T>* childNode = new TreeNode<T>(childData);
            curentNode->child.push_back(childNode);
            storage.push(childNode);
        }
    }
    return rootNode;
}

void printTree(TreeNode<int> * rootNode){
    queue<TreeNode<int>*> storage;
    storage.push(rootNode);
    while(!storage.empty()){
        TreeNode<int> * curentNode = storage.front();
        storage.pop();
        cout << curentNode->data << ":";
        for(int i = 0; i < curentNode->child.size(); i ++){
            cout << curentNode->child[i]->data;
            if(i != curentNode->child.size() - 1)
            cout << ","; 
            storage.push(curentNode->child[i]);
        }
        cout << endl;
    }
}

int main(){
    TreeNode<int> * rootNode = takeTreeInput<int>();
    printTree(rootNode);
    return 0;
}