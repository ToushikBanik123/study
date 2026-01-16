#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    TreeNode<T> * l;
    TreeNode<T> * r;

    TreeNode(T data){
        this->data = data;
        this->l = NULL;
        this->r = NULL;
    }
    ~TreeNode(){
        if(l) delete l;
        if(r) delete r;
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    if(rootNodeData == -1) return NULL;

    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);
    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        T l;
        T r;

        cin >> l;
        cin >> r;
        if(l != -1){
            curentNode->l = new TreeNode<T>(l);
            storage.push(curentNode->l);
        }
        if(r != -1){
            curentNode->r = new TreeNode<T>(r);
            storage.push(curentNode->r);
        }
    }
    return rootNode;
}

template <typename T>
bool findx(TreeNode<T> * rootNode, T x){
    if(rootNode == NULL) return 0;
    return (rootNode->data == x) || findx<T>(rootNode->l,x) || findx<T>(rootNode->r,x);
}


int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int x;
    cin >> x;
    if(findx<int>(rootNode,x)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}