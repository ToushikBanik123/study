#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> child;
    TreeNode(T data){
        this->data = data;
    }
};

template <typename T>
TreeNode<T> * takrTreeInput(){
    T rootNodeData; 
    queue<TreeNode<T>*> storage;

    cin >> rootNodeData;

    TreeNode<T> * rootNode = new TreeNode<T>(rootNodeData);
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int childCount;
        cin >> childCount;

        for(int i = 0; i < childCount; i++){
            T chiledNodeData;
            cin >> chiledNodeData;

            TreeNode<T> * childNode = new TreeNode<T>(chiledNodeData);
            curentNode->child.push_back(childNode);
            storage.push(childNode);
        }
    }

    return rootNode;
}

template <typename T>
void printTree(TreeNode<T> * rootNode){
    queue<TreeNode<T>*> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();
        cout << curentNode->data << ":";

        for(int i = 0; i < curentNode->child.size(); i++){
            cout<< curentNode->child[i]->data << ",";
            storage.push(curentNode->child[i]);
        }

        cout << endl;
    }
}

int sumOfAllNoes(TreeNode<int>* rootNode){
    int sum = rootNode->data;
    for(int i = 0; i < rootNode->child.size();i++){
        sum += sumOfAllNoes(rootNode->child[i]);
    }
    return sum;
}

int main(){
    TreeNode<int>* rootNode = takrTreeInput<int>();
    printTree<int>(rootNode);
    cout << "The sum of all the nodes will be : " << sumOfAllNoes(rootNode);
    return 0;
}