#include <iostream>
#include <vector>
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
        if(curentNode->left){
            storage.push(curentNode->left);
        }
        if(curentNode->right){
            storage.push(curentNode->right);
        }
    }
}

template <typename T>
vector<T> takeArrayInput(int size){
    vector<T> ans;
    for(int i = 0; i < size; i++){
        int input;
        cin >> input;
        ans.push_back(input);
    }
    return ans;
}

template <typename T>
void preorderPriunt(TreeNode<T> * rootNode){
    if(rootNode == NULL) return;
    cout << rootNode->data << " ";
    if(rootNode->left) preorderPriunt<T>(rootNode->left);
    if(rootNode->right) preorderPriunt<T>(rootNode->right);
}

template <typename T>
TreeNode<T> * creatBST(vector <T> &sortedArrray, int start, int end){
    if(end<start) return NULL;
    int mid = start + (end-start)/2;
    TreeNode<T> * rootNode = new TreeNode<T>(sortedArrray[mid]);
    rootNode->left = creatBST(sortedArrray, start, mid-1);
    rootNode->right = creatBST(sortedArrray,mid+1,end);
    return rootNode;
}

int main(){
    int size;
    cin >> size;
    vector<int> sortedArrray = takeArrayInput<int>(size);
    TreeNode<int> * rootNode = creatBST<int>(sortedArrray,0,size-1);
    printTree<int>(rootNode);
    cout << endl;
    preorderPriunt<int>(rootNode);
    return 0;
}