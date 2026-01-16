#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode<T>*> child;

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i = 0; i < child.size(); i++){
            delete child[i];
        }
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodedata;
    cin >> rootNodedata;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodedata);

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);
    while(!storage.empty()){
        TreeNode<T> * curentNode =  storage.front();
        storage.pop();

        T curentNodeChildCount;
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childeNode = new TreeNode<T>(childNodeData);

            storage.push(childeNode);
            curentNode->child.push_back(childeNode);
        }
    }
    return rootNode;
}

template <typename T>
bool findX(TreeNode<T> * rootNode, T x){
    if(rootNode == NULL) return 0;
    if(rootNode->data == x) return 1;
    for(int i = 0; i < rootNode->child.size(); i++){
        if(findX<T>(rootNode->child[i], x)) return 1;
    }
    return 0;
}

int main(){
    int x;
    TreeNode<int> * rootNode = takeInput<int>();
    cin >> x;
    if(findX<int>(rootNode,x)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}