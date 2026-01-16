#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> child;
    //Constructor
    TreeNode(T data){
        this->data = data;
    }
    //Distructor
    ~TreeNode(){
        for(int i = 0; i < child.size(); i++){
            delete child[i];
        }
    }
};

template <typename T>
TreeNode<T>* takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    TreeNode<T>* rootNode = new TreeNode<T>(rootNodeData);

    queue <TreeNode<T>* > storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T>* curentNode = storage.front();
        storage.pop();

        int childNodeCount;
        cin >> childNodeCount;

        for(int i = 0; i < childNodeCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T>* childNode = new TreeNode<T>(childNodeData);

            storage.push(childNode);
            curentNode->child.push_back(childNode);
        }
    }
    return rootNode;
}

template <typename T> 
TreeNode<T>* compareNode(TreeNode<T>* n1, TreeNode<T>* n2, int x){
    if(n1 == NULL && n2 == NULL) return NULL;
    if(n1 == NULL && x < n2->data) return n2;
    if(n1 == NULL && x > n2->data) return NULL;
    if(n2 == NULL && x < n1->data) return n1;
    if(n2 == NULL && x > n1->data) return NULL;
    if(n1->data < x) return n2;
    if(n2->data < x) return n1;
    if(n1->data < n2->data) return n1;
    return n2;
}

template <typename T>
TreeNode<T>* nextLargeNode(TreeNode<T>* rootNode, int x){
    if(rootNode == NULL) return NULL;
    TreeNode<T>* val = NULL;
    if(x < rootNode->data){
        val = rootNode;
    }
    for(int i = 0; i < rootNode->child.size(); i++){
        TreeNode<T>* curentNode = rootNode->child[i];
        TreeNode<T>* nextNode = nextLargeNode(curentNode,x);
        val = compareNode<int>(val,nextNode,x);
    }
    return val;
}

int main(){
    int x;
    cin >> x;
    TreeNode<int>* rootNode = takeInput<int>();
    if(nextLargeNode<int>(rootNode,x)){
        cout << nextLargeNode<int>(rootNode,x)->data;
    }
    return 0;
}