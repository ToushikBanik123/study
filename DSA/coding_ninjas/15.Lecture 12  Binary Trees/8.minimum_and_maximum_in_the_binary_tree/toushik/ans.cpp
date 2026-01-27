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
class minMax{
    public:
    T min;
    T max;

    minMax(T min, T max){
        this->min = min;
        this->max = max;
    }
};

template <typename T>
TreeNode<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int leftData;
        int rightData;

        cin >> leftData;
        cin >> rightData;

        if(leftData != -1){
            curentNode->left = new TreeNode<T>(leftData);
            storage.push(curentNode->left);
        }

        if(rightData != -1){
            curentNode->right = new TreeNode<T>(rightData);
            storage.push(curentNode->right);
        }
    }
    return rootNode;
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T> *> storage;
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        if(curentNode == NULL){
            cout << endl;
            if(!storage.empty()){
                storage.push(NULL);
            }
            continue;
        }
        cout << curentNode->data << " ";
        if(curentNode->left) storage.push(curentNode->left);
        if(curentNode->right) storage.push(curentNode->right);
    }
}

template <typename T>
minMax<T> * findTheMinMax(TreeNode<T> * rootNode){
    if(rootNode == NULL){
        return new minMax<T>(
            INT_MAX,
            INT_MIN
        );
    }
    
    minMax<T> * leftData = findTheMinMax<T>(rootNode->left);
    minMax<T> * rightData = findTheMinMax<T>(rootNode->right);

    int min = std::min(rootNode->data, std::min(leftData->min, rightData->min));
    int max = std::max(rootNode->data, std::max(leftData->max, rightData->max));
    minMax<T> * ans = new minMax<T>(min,max);
    return ans;
} 

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    printTree<int>(rootNode);
    minMax<int>*  ans = findTheMinMax<int>(rootNode);
    cout << "Min val : " << ans->min << endl;
    cout << "Max val : " << ans->max << endl;
    return 0;
}