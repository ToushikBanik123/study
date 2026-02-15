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
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> *  curentNode = storage.front();
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
bool searchNode(TreeNode<T> * rootNode, T data){
    if(rootNode == NULL) return false;
    if(rootNode->data == data) return true;
    if(rootNode-> data < data) {
        return searchNode(rootNode->right,data);
    }else{
        return searchNode(rootNode->left,data);
    }
}

int main(){
    cout << "Enter the Tree : ";
    TreeNode<int> * rootNode = takeInput<int>();
    cout << "Enter the data you want to fond : ";
    int data;
    cin >> data;

    if(searchNode<int>(rootNode,data)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}