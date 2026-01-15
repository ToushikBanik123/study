#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> child;

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
    T treeNodeData;
    cin >> treeNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(treeNodeData);
    
    queue<TreeNode<T>*> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int childCount;
        cin >> childCount;
        for(int i = 0; i < childCount; i++){
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
void postOrderPrint(TreeNode<T> * rootNode){
    if(rootNode == NULL) return;
    for(int i = 0; i < rootNode->child.size(); i ++){
        postOrderPrint<T>(rootNode->child[i]);
    }
    cout << rootNode->data << " ";
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    postOrderPrint(rootNode);
    return 0;
}