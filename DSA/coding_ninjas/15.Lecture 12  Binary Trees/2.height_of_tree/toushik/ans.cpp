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

    queue <TreeNode<T> *> storage;
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
int findHight(TreeNode<T> * rootNode){
    if(rootNode == NULL) return 0;

    int hight = 1;
    int legtHight = 0;
    int rightHight = 0;

    if(rootNode->left)
    legtHight = findHight(rootNode->left);
    if(rootNode->right)
    rightHight = findHight(rootNode->right);

    if(legtHight < rightHight){
        hight += rightHight;
    }else{
        hight += legtHight;
    }

    return  hight;
}

int main(){
    cout << "Enter the Tree : ";
    TreeNode<int> * rootNode = takeInput<int>();
    int hight = findHight<int>(rootNode);
    cout << hight << endl;
    delete rootNode;
    return 0;
}