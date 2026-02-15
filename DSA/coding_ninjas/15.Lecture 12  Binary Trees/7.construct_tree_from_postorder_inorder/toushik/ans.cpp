#include <iostream>
#include <vector>
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
vector<T> takeInput(int size){
    vector<T> nums;
    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    return nums;
}

template <typename T>
void printVector(vector<T> &vect,int size){
    for(auto it : vect){
        cout << it << " ";
    }
    cout << endl;
}

template <typename T>
TreeNode<T> * buildTree(
    vector<T> &postorder,
    vector<T> &inorder,
    int postorderStartIndex,
    int postorderEndIndex,
    int inorderStartIndex,
    int inorderEndIndex
    ){
    if (postorderStartIndex > postorderEndIndex ||
    inorderStartIndex > inorderEndIndex) {
        return NULL;
    }
    TreeNode<T> * rootNode = new TreeNode<T>(postorder[postorderEndIndex]);
    int inorderRootIndex = inorderStartIndex;
    while(inorderRootIndex <= inorderEndIndex && 
        inorder[inorderRootIndex] != rootNode->data){
        inorderRootIndex++;
    }

    //for Left Recurtion
    int leftPostorderStartIndex = postorderStartIndex;
    int leftPostorderEndIndex = (postorderStartIndex + (inorderRootIndex-inorderStartIndex) - 1);
    
    int leftInorderStartIndex = inorderStartIndex;
    int leftInorderEndIndex = inorderRootIndex - 1;

    rootNode->left = buildTree(
        postorder,
        inorder,
        leftPostorderStartIndex,
        leftPostorderEndIndex,
        leftInorderStartIndex,
        leftInorderEndIndex
    );

    //for Right Recurtion
    int rightPostorderStartIndex = (postorderStartIndex + (inorderRootIndex-inorderStartIndex));
    int rightPostorderEndIndex = (postorderEndIndex - 1);

    int rightInorderStartIndex = inorderRootIndex + 1;
    int rightInorderEndIndex = inorderEndIndex;

    rootNode->right = buildTree(
        postorder,
        inorder,
        rightPostorderStartIndex,
        rightPostorderEndIndex,
        rightInorderStartIndex,
        rightInorderEndIndex
    );
    
    return rootNode;
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T> * > storage; 
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        if(curentNode == NULL){
            if(!storage.empty())
            storage.push(NULL);
            cout << endl;
            continue;
        }
        if(curentNode->left)
        storage.push(curentNode->left);
        if(curentNode->right)
        storage.push(curentNode->right);
        cout << curentNode->data << " ";
    }
}

int main(){
    int size; 
    cin >> size; 
    vector<int> postorder = takeInput<int>(size);
    vector<int> inorder = takeInput<int>(size);
    printVector<int>(postorder,size);
    printVector<int>(inorder,size);

    int postorderStartIndex = 0; 
    int postorderEndIndex = size -1;
    int inorderStartIndex = 0;
    int inorderEndIndex = size -1;

    TreeNode<int> * rootNode = buildTree<int>(
        postorder,
        inorder,
        postorderStartIndex,
        postorderEndIndex,
        inorderStartIndex,
        inorderEndIndex
    );
    printTree(rootNode);

    return 0;
}