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
class Ans{
    public:
    TreeNode<T> * data;
    bool x;
    bool y;
    Ans(){
        this->data = NULL;
        this->x = 0;
        this->y = 0;
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
Ans<T> findLCA(T x, T y, TreeNode<T> * rootNode){
    Ans<T> ans;
    if(rootNode == NULL){
        return ans;
    }
    Ans<T> left = findLCA<T>(x,y,rootNode->left);
    if(left.x && left.y) return left;

    Ans<T> right = findLCA<T>(x,y,rootNode->right);
    if(right.x && right.y) return right;

    if(left.x || right.x || rootNode->data == x){
        ans.x = 1;
    }
    if(left.y || right.y || rootNode->data == y){
        ans.y = 1;
    }

    if(ans.x && ans.y){
        ans.data = rootNode;
    }
    return ans;
}


int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    int x;
    int y;
    cin >> x >> y;
    Ans<int> ans = findLCA<int>(x,y,rootNode);
    
    if(ans.x || ans.y){
        cout << ans.data->data << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}