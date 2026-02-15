#include <iostream>
#include <queue>
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
class ListeNode{
    public:
    T data;
    ListeNode<T> * next;
    ListeNode(T data){
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class Path{
    public:
    bool onPath;
    ListeNode<T> * head;

    Path(bool onPath){
        this->onPath = onPath;
        head = NULL;
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
Path<T> findPath(TreeNode<T> * rootNode, int &x){
    if(rootNode == NULL) return Path<T>(0);
    if(rootNode->data == x){ 
        Path<T> path = Path<T>(1);
        path.head = new ListeNode<T>(rootNode->data);
        return path;
    }
    if(x < rootNode->data){
        Path<T> left = findPath<T>(rootNode->left,x);
        if(left.onPath){
            ListeNode<T> * temp = left.head;
            left.head = new ListeNode<T>(rootNode->data);
            left.head->next = temp;
            return left;
        }
    }else{
        Path<T> right = findPath<T>(rootNode->right,x);
        if(right.onPath){
            ListeNode<T> * temp = right.head;
            right.head = new ListeNode<T>(rootNode->data);
            right.head->next = temp;
            return right;
        }
    }
    return Path<T>(0);
}


template <typename T>
void printPath(TreeNode<T> * rootNode, int & x){
    Path<T> path = findPath<T>(rootNode, x);
    if(!path.onPath){
        cout << "-1" << endl;
    }else{
        while(path.head != NULL){
            cout << path.head->data << " ";
            path.head = path.head->next;
        }
    }
}


int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int x; 
    cin >> x;
    printPath<int>(rootNode,x);
}