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
    bool isRight = 1;

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        if(curentNode == NULL){
            cout << endl;
            if(!storage.empty()){
                storage.push(NULL);
                isRight = !isRight;
            }
            continue;
        }

        cout << curentNode->data << " ";
        if(isRight){
            if(curentNode->right){
                storage.push(curentNode->right);
            }
            if(curentNode->left){
                storage.push(curentNode->left);
            }
        }else{
            if(curentNode->left){
                storage.push(curentNode->left);
            }
            if(curentNode->right){
                storage.push(curentNode->right);
            }
        }
    }
}

int main(){
    TreeNode<int>* rootNode = takeInput<int>();
    printTree<int>(rootNode);
    return 0;
}
