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

class minMaxBST{
    public:
    bool isBST;
    int min;
    int max;

    minMaxBST(bool isBST, int min, int max){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
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
minMaxBST isBST(TreeNode<T> * rootNode){
    //edge-case
    if(root == NULL){
        return MinMaxBST(true, INT_MAX, INT_MIN);
    }
    minMaxBST lc = {0,0,0};
    minMaxBST rc = {0,0,0};
    //Basecase + conditonal parcing 
    if(rootNode->left){
        lc = isBST(rootNode->left);
    }else{
        lc = {true,rootNode->data, rootNode->data};
    }    

    if(rootNode->right){
        rc = isBST(rootNode->right);
    }else{
        rc = {true,rootNode->data, rootNode->data};
    }  

    if(!lc.isBST || !rc.isBST) return {false, 0,0};
    if(lc.max > rootNode->data || rc.min < rootNode->data) return {false,0,0};
    return{true, lc.min,rc.max};
}

int main(){
    TreeNode<int>* rootNode = takeInput<int>();
    if(isBST<int>(rootNode).isBST){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}
