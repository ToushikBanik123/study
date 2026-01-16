#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public : 
    T data;
    vector<TreeNode<T> * > child;
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
    T rootData;
    cin >> rootData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootData);

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();
        
        int curentNodeChildCount; 
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);

            storage.push(childNode);
            curentNode->child.push_back(childNode);
        }
    }
    return rootNode;
}

template <typename T>
int higherValueCount(TreeNode<T> * rootNode, T x){
    if(rootNode == NULL) return 0;
    int count = 0;
    if(x<rootNode->data) {
        count++;
    }
    for(int i = 0; i < rootNode->child.size(); i++){
        count += higherValueCount<T>(rootNode->child[i],x);
    }
    return count;
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int x;
    cin >> x;
    cout << higherValueCount<int>(rootNode,x);
    return 0;
}