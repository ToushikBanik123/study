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
void work(TreeNode<T> * rootNode){
    if(rootNode == NULL) return;
    TreeNode<T> * temp = rootNode->left;
    rootNode->left = new TreeNode<T>(rootNode->data);
    rootNode->left->left = temp;

    work<T>(rootNode->right);
    work<T>(temp);
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T> *> storage;
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();
        if(curentNode == NULL){
            if(!storage.empty()){
                storage.push(curentNode);
                cout << endl;
            }
            continue;
        }
        cout<< curentNode->data << " ";
        if(curentNode->left != NULL) storage.push(curentNode->left);
        if(curentNode->right != NULL) storage.push(curentNode->right);
    }
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    work<int>(rootNode);
    printTree<int>(rootNode);
    return 0;
}