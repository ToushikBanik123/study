#include <iostream>
#include <queue>
#include <vector>
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
};

template <typename T>
class PathNode{
    public:
    TreeNode<T> * node;
    char path;
    PathNode(TreeNode<T> * node, char path){
        this->node = node;
        this-> path = path;
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
        TreeNode<T> * curent = q.front();
        q.pop();

        T left;
        T right;
        cin >> left >> right;
        
        if(left != -1){
            curent->left = new TreeNode<T>(left);
            q.push(curent->left);
        }

        if(right != -1){
            curent->right = new TreeNode<T>(right);
            q.push(curent->right);
        }
    }
    return rootNode;
}

template <typename T>
vector<PathNode<T>> findThePathHelper (T n, TreeNode<T> * rootNode){

}

template <typename T>
vector<PathNode<T>> findThePath(T n, TreeNode<T> * rootNode){

}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int n; 
    int k;
    cin >> n > k;
    vector<PathNode<int>> path = findThePath();
    return 0;
}