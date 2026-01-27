#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node * next; 

    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

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
vector<pair<Node<TreeNode <T> *> * ,Node<TreeNode <T> *> * >> vectoredList(TreeNode<T> * rootNode){
    vector<pair<Node<TreeNode <T> *> * ,Node<TreeNode <T> *> * >> ans;
    ans.push_back({NULL, NULL});

    queue<TreeNode <T> *> storage;
    storage.push(rootNode);
    storage.push(NULL);

    while(!storage.empty()){
        TreeNode <T> * curentNode = storage.front();
        storage.pop();
        

        //New Level 
        if(curentNode == NULL){
            if(!storage.empty()){
                storage.push(NULL);
                pair<Node<TreeNode<T>*>*, Node<TreeNode<T>*>*> newIndex = {NULL,NULL};
                ans.push_back(newIndex);
            }
            continue;
        }
        //Same Lavel 
        Node<TreeNode<T>*> * node = new Node<TreeNode<T>*>(curentNode);

        Node<TreeNode <T> *> *  &headPtr = ans.back().first;
        Node<TreeNode <T> *> *  &talePtr = ans.back().second;

        if(talePtr == NULL){
            headPtr = node;
            talePtr = node;
        }else{
            talePtr->next = node;
            talePtr = talePtr->next;
        }
        if(curentNode->left){
            storage.push(curentNode->left);
        }
        if(curentNode->right){
            storage.push(curentNode->right);
        }
    }
    return ans;
}

template <typename T >
void printIt(vector<pair<Node<TreeNode <T> *> * ,Node<TreeNode <T> *> * >> ans){
    for(int i = 0; i < ans.size(); i++){
        pair<Node<TreeNode <T> *> * ,Node<TreeNode <T> *> * > curentNode = ans[i];
        Node<TreeNode <T> *> * ptr = curentNode.first;

        while(ptr != NULL){
            cout << ptr->data->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main(){
    TreeNode<int> * rootNode = takeInput<int>();
    vector<pair<Node<TreeNode <int> *> * ,Node<TreeNode <int> *> * >> ans = vectoredList<int>(rootNode);
    printIt<int>(ans);
    return 0;
}