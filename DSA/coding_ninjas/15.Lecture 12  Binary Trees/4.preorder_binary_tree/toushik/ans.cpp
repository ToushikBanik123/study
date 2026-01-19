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

    ~TreeNode(){
        if(left) delete left;
        if(right) delete right;
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    if(rootNodeData == -1) return NULL;
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

template <typename T>
void printList(TreeNode<T> * rootNode){
    if(rootNode == NULL) return;
    cout << rootNode->data << " ";
    if(rootNode->left) printList<T>(rootNode->left);
    if(rootNode->right) printList<T>(rootNode->right);
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    printList<int>(rootNode);
    if(rootNode) delete rootNode;
    return 0;
}