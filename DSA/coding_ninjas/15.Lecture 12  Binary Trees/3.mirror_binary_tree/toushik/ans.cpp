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
        left = NULL;
        right = NULL;
    }

    ~TreeNode(){
        if(left)
        delete left;
        if(right)
        delete right;
    }
};

template <typename T>
TreeNode<T> *  takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    if(rootNodeData == -1) return NULL;
    
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);
    queue <TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        T left; 
        T right;

        cin >> left;
        cin >> right;

        if(left != -1) curentNode->left = new TreeNode<T>(left);
        if(left != -1) storage.push(curentNode->left);
        if(right != -1) curentNode->right = new TreeNode<T>(right);;
        if(right != -1) storage.push(curentNode->right);
    }

    return rootNode;
}

template <typename T>
void mirrorTree(TreeNode<T> * rootNode){
    if(rootNode == NULL) return; 

    mirrorTree(rootNode->left);
    mirrorTree(rootNode->right);

    TreeNode<T> * temp = rootNode->left; 
    rootNode->left = rootNode->right;
    rootNode->right = temp;
}

template <typename T>
void printTree(TreeNode<T> *rootNode){
    if(rootNode == NULL) return;

    queue<TreeNode<T>*> q;
    q.push(rootNode);
    q.push(NULL); // level separator

    while(!q.empty()){
        TreeNode<T>* current = q.front();
        q.pop();

        if(current == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
            continue;
        }

        cout << current->data << " ";

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}



int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    mirrorTree(rootNode);
    printTree(rootNode);
    return 0;
}
