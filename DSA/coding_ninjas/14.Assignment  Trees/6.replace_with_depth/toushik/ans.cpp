#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> * > child;

    TreeNode(T data){
        this->data = data;
    }
};

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

        int childCount;
        cin >> childCount;
        for(int i = 0; i < childCount; i++){
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
void updateDepth(TreeNode<T> * rootNode, int depth = 0){
    rootNode->data = depth;
    depth++;
    for(int i = 0; i < rootNode->child.size(); i++){
        updateDepth(rootNode->child[i],depth);
    }
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T> * > q;
    q.push(rootNode);
    cout << q.front()->data << " " <<endl;

    while(!q.empty()){
        TreeNode<T> * curentNode = q.front();
        q.pop();
        for(int i = 0; i < curentNode->child.size(); i++){
            cout << curentNode->child[i]->data << " ";
            q.push(curentNode->child[i]);
        }
        cout << endl;
    }
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    updateDepth<int>(rootNode);
    printTree<int>(rootNode);
    return 0;
}