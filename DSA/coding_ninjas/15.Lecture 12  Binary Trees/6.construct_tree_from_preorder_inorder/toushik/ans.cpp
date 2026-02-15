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
    vector<T> v;
    for(int i = 0; i < size; i++){
        T temp;
        cin >>temp;
        v.push_back(temp);
    }
    return v;
}

// template <typename T>
// TreeNode<T> * creatTree(vector<T> & PO, vector<T> &IO, int size){
//     if(!PO.size()) return NULL;
//     TreeNode<T> * rootNode = new TreeNode<T>(PO[0]);
//     if(PO.size() == 1) return rootNode;

//     int LeftSize = 0;
//     int RightSize = 0;

//     while(true){
//         LeftSize++;
//         if(IO[LeftSize] == PO[0]) break;
//     }
    
//     RightSize = size - LeftSize - 1;

//     vector<T> * LeftPO = PO + 1;
//     vector<T> * RightPO = LeftPO + LeftSize;

//     vector<T> * LeftIO = IO;
//     vector<T> * RightIO = IO + LeftSize + 1;

//     rootNode->left = creatTree(LeftPO,LeftIO,LeftSize);
//     rootNode->right = creatTree(RightPO,RightIO,RightSize);
//     return rootNode;
// }

template <typename T>
TreeNode<T> * creatTree(
    vector<T> & inOrder,
    vector<T> &preOrder,
    int inOrderStart,
    int inOrderEnd,
    int preOrderStart,
    int preOrderEnd
    ){
        //if preorder is empty then
        if (preOrderStart > preOrderEnd || inOrderStart > inOrderEnd) return NULL;
        TreeNode<T> * rootNode = new TreeNode<T>(preOrder[preOrderStart]);

        int count = inOrderStart;
        while(inOrder[count] != rootNode->data){
            count++;
        }
        int 
        rootNode->left = creatTree(inOrder,preOrder,inOrderStart, count -1, preOrderStart+1, preOrderStart + (count-inOrderStart));
        rootNode->right = creatTree(inOrder,preOrder,count + 1, inOrderEnd, preOrderStart+1 + (count-inOrderStart), preOrderEnd);
        return rootNode;
    }


template <typename T>
void printVector(vector<T> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    if (!rootNode) return;

    queue<TreeNode<T> *> storage;
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        if(curentNode == NULL){
            cout << endl;
            if(storage.empty()) break;
            storage.push(NULL);
            continue;
        }

        cout << curentNode->data << " ";

        if(curentNode->left) storage.push(curentNode->left);
        if(curentNode->right) storage.push(curentNode->right);
    }
}


int main(){
    int size; 
    cin >> size;
    vector <int> preOrder = takeInput<int>(size);
    vector <int> inOrder = takeInput<int>(size);
    printVector<int>(preOrder);
    printVector<int>(inOrder);

    TreeNode<int> *  rootNode = creatTree<int>(inOrder , preOrder, 0, size-1, 0 , size-1);
    printTree<int>(rootNode);
    return 0;
}