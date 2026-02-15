#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    TreeNode<T> * left;
    TreeNode<T> * right;

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

    queue<TreeNode<T> * > storage;
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

template <typename T>
void printInRange(TreeNode<T> * rootNode, T lb, T ub){
    if(rootNode == NULL) return;
    T data = rootNode->data;
        if(lb < data && rootNode->left) printInRange<T>(rootNode->left,lb,ub);
        if(data >= lb && data <= ub)
        cout << data << " ";
        if(data < ub && rootNode->right) printInRange<T>(rootNode->right,lb,ub);
    return;
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int lb,ub;
    cin >> lb;
    cin >> ub;
    printInRange<int>(rootNode,lb,ub);
    return 0;
}