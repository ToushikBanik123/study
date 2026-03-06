#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    TreeNode * left;
    TreeNode * right;

    TreeNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

        T left;
        T right;

        cin >> left;
        cin >> right;

        if(left != -1){
            curentNode->left = new TreeNode<T>(left);
            storage.push(curentNode->left);
        }

        if(right != -1){
            curentNode->right = new TreeNode<T>(right);
            storage.push(curentNode->right);
        }
    }

    return rootNode;
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    return 0;
}