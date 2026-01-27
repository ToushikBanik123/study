#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
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

        cout << curentNode->data;
        if(curentNode->left){
            storage.push(curentNode->left);
        }
        if(curentNode->right){
            storage.push(curentNode->right);
        }
    }
}

template<typename T>
pair<bool,int> checkTheNode(TreeNode<T> * rootNode){
    if(rootNode == NULL){
        pair<bool,int> ans = {true,0};
        return ans;
    }
    pair<bool, int> left = checkTheNode<T>(rootNode->left);
    pair<bool, int> right = checkTheNode<T>(rootNode->right);

    bool balanced; 
    if(left.first == false ||
        right.first == false || 
        max(left.second, right.second) - min(left.second, right.second) > 1){
        balanced = false;
    }else{
        balanced = true;
    }

    int hight = 1 + max(left.second, right.second);
    
    return {balanced,hight};
}

template <typename T>
bool isBalanced(TreeNode<T> * rootNode){
    pair<bool,int> result = checkTheNode<T>(rootNode);
    return result.first;
}

int main(){
    TreeNode<int>* rootNode = takeInput<int>();
    printTree<int>(rootNode);
    if(isBalanced(rootNode)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}