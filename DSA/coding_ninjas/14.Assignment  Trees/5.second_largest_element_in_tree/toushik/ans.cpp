#include <iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector <TreeNode<T> *> child;
    TreeNode(T data){
        this->data = data;
    }
};

class H

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);

    queue<TreeNode<T> *> q;
    q.push(rootNode);

    while(!q.empty()){
        TreeNode<T> * curentNode = q.front();
        q.pop();
        int curentNodeChildCount;
        cin >> curentNodeChildCount;

        for(int i = 0; i < curentNodeChildCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);

            q.push(childNode);
            curentNode->child.push_back(childNode);
        }
    }
    return rootNode;
}

template <typename T>
    TreeNode<T> * findTheSecorLargest(TreeNode<T> * rootNode, int x){
    return rootNode;
}


int main(){
    cout << "Enter the Tree Value : ";
    TreeNode<int> * rootNode = takeInput<int>();

    int x;
    cout <<"Enter the value (x) : ";
    cin >> x;

    cout << findTheSecorLargest(rootNode,x)->data;
    return 0;
}