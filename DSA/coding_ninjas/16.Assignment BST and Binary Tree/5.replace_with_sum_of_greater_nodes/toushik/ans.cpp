#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    TreeNode <T> * left;
    TreeNode <T> * right;

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
TreeNode <T> * takeInput(){
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
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T> *> storage;
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        if(curentNode == NULL){
            cout << endl;
            if(!storage.empty()){
                storage.push(NULL);
            }
            continue;
        }

        cout << curentNode->data << " ";
        if(curentNode->left){
            storage.push(curentNode->left);
        }
        if(curentNode->right){
            storage.push(curentNode->right);
        }
    }
}

template <typename T>
T replaceSum(TreeNode<int>* rootNode, T value = 0){
    if(rootNode == NULL) return 0;
    T RS = replaceSum(rootNode->right,value);

    T returnVal = rootNode->data + RS;
    rootNode->data = returnVal + value;

    T LS = replaceSum(rootNode->left,rootNode->data);
    return returnVal;
}

int main(){
    TreeNode<int>* rootNode = takeInput<int>();
    printTree<int>(rootNode);
    replaceSum<int>(rootNode,0);
    printTree<int>(rootNode);
    delete rootNode;
    return 0;
}
