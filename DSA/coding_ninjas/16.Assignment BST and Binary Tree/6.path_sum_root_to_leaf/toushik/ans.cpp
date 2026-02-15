#include <iostream>
#include <queue>
#include <vector>
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

void printPath(TreeNode<int> * rootNode,int &k, int &sum, vector<int> &path){
    if(!rootNode) return;
    
    sum = sum + rootNode->data;
    path.push_back(rootNode->data);

    if(rootNode->left == NULL && rootNode->right == NULL){
        if(sum == k){
            for(int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }
            cout << endl;
        }
    }else{
        if(rootNode->left){
            printPath(rootNode->left, k, sum, path);
        }
        if(rootNode->right){
            printPath(rootNode->right, k, sum, path);
        }
    }

    sum = sum - rootNode->data;
    path.pop_back();
}

int main(){
    TreeNode<int>* rootNode = takeInput<int>();
    // printTree<int>(rootNode);
    int k; 
    int sum = 0;

    cin >> k;
    vector<int> path;

    printPath(rootNode,k,sum, path);
    return 0;
}
