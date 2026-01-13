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

    queue<TreeNode<T>*> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        TreeNode<T> * curentNode = storage.front();
        storage.pop();

        int curentNodeChildCount;
        cin >> curentNodeChildCount;

        for(int i = 0;i < curentNodeChildCount; i++){
            T val;
            cin >> val;

            TreeNode<T> * childNode = new TreeNode<T>(val);

            curentNode->child.push_back(childNode);
            storage.push(childNode);
        }
    }

    return rootNode;
}


template <typename T>
int findTheHight(TreeNode<T>* rootNode){
    int hight = 0;
    for(int i = 0; i < rootNode->child.size(); i++){
        int childesHight = findTheHight<T>(rootNode->child[i]);
        if(hight < childesHight){
            hight = childesHight;
        }
    }
    return hight + 1;
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    cout << "Your Trees Hight is : " << findTheHight<int>(rootNode) << endl;
    return 0;
}