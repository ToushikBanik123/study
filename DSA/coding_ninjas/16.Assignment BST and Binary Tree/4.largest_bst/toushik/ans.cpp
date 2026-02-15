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
class ChildDetaild{
    public:
    bool isBST;
    int hight;
    T lowestValue;
    T hightValue;
    ChildDetaild(){
        this->isBST = 0;
        this->hight = -1;
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
ChildDetaild<T> largestBSTHight(TreeNode<T> * rootNode){
    ChildDetaild<T> ans;

    if(rootNode->left == NULL && rootNode->right == NULL){
        ans.isBST = 1;
        ans.hight = 1;
        ans.lowestValue = rootNode->data;
        ans.hightValue = rootNode->data;
        return ans;
    }
    ChildDetaild<T> LD;
    ChildDetaild<T> RD;

    if(rootNode->left)
    LD = largestBSTHight(rootNode->left);
    if(rootNode->right)
    RD = largestBSTHight(rootNode->right);

    if(rootNode->left && rootNode->right){
        ChildDetaild<T> LargeData;
        if(LD.hight > RD.hight){
            LargeData = LD;
        }else{
            LargeData = RD;
        }

        if(LD.isBST && RD.isBST){
            if(LD.hightValue < rootNode->data && rootNode->data < RD.lowestValue){
                LargeData.hight++;
                LargeData.lowestValue = LD.lowestValue;
                LargeData.hightValue = RD.hightValue;
                return LargeData;
            }
        }
        LargeData.isBST = 0;
        return LargeData;
    }else if(rootNode->left && rootNode->right == NULL){
        if(LD.isBST){
            if(LD.hightValue < rootNode->data){
                LD.hight++;
                LD.hightValue = rootNode->data;
                return LD;
            }
        }
        LD.isBST = 0;
        return LD;
    }else{
        if(RD.isBST){
            if(rootNode->data < RD.lowestValue){
                RD.hight++;
                RD.lowestValue = rootNode->data;
                return RD;
            }
        }
        RD.isBST = 0;
        return RD;
    }
}


int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    cout << largestBSTHight<int>(rootNode).hight << endl;
    delete rootNode;
    return 0;
}