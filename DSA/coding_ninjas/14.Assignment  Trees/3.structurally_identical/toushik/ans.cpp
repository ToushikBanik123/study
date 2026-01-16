#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> child;
    
    TreeNode(T data){
        this->data = data;
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

       int childCount;
       cin >> childCount;
       for(int i = 0; i < childCount; i++){
            T childNodeData;
            cin >> childNodeData;
            TreeNode<T> * childNode = new TreeNode<T>(childNodeData);

            storage.push(childNode);
            curentNode->child.push_back(childNode);
       }
    }
    return rootNode;
}

template <typename T>
bool compareTwoNode(TreeNode<T> * rootNode1, TreeNode<T> * rootNode2){
    if (rootNode1 == NULL && rootNode2 == NULL) return true;
    if (rootNode1 == NULL || rootNode2 == NULL) return false;

    if(rootNode1->data != rootNode2->data) return false;
    if(rootNode1->child.size() != rootNode2->child.size()) return false;
    for(int i = 0; i < rootNode2->child.size(); i++){
        if(rootNode1->child[i]->data != rootNode2->child[i]->data) return false;
    }
    return true;
}

template <typename T>
bool compareList(TreeNode<T> * rootNode1, TreeNode<T> * rootNode2){
    bool result = compareTwoNode<T>(rootNode1,rootNode2);
    for(int i = 0; i < rootNode1->child.size(); i++){
        result = result && compareList<T>(rootNode1->child[i], rootNode2->child[i]);
    }
    return result;
}

int main(){
    cout << "Enter your 1st Linked List : ";
    TreeNode<int> * rootNode1 = takeInput<int>();

    cout << "Enter your 2st Linked List : ";
    TreeNode<int> * rootNode2 = takeInput<int>();

    bool result = compareList<int>(rootNode1,rootNode2);
    
    if(result){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}