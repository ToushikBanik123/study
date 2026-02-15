#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class ListNode{
public:
    T data;
    ListNode<T>* next;

    ListNode(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class TreeNode{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data){
        this->data = data;
        left = right = NULL;
    }

    ~TreeNode(){
        if(left) delete left;
        if(right) delete right;
    }
};

template <typename T>
class HeadAndTail{
public:
    ListNode<T>* head;
    ListNode<T>* tail;

    HeadAndTail(){
        head = tail = NULL;
    }
};

template <typename T>
HeadAndTail<TreeNode<T>*> treeToList(TreeNode<T>* root){

    HeadAndTail<TreeNode<T>*> ans;

    if(root == NULL) return ans;

    auto left = treeToList(root->left);
    auto right = treeToList(root->right);

    ListNode<TreeNode<T>*>* current =
        new ListNode<TreeNode<T>*>(root);

    // attach left
    if(left.head){
        ans.head = left.head;
        left.tail->next = current;
    }else{
        ans.head = current;
    }

    // attach right
    if(right.head){
        current->next = right.head;
        ans.tail = right.tail;
    }else{
        ans.tail = current;
    }

    return ans;
}

template <typename T>
void printList(HeadAndTail<TreeNode<T>*>& list){

    ListNode<TreeNode<T>*>* temp = list.head;

    while(temp){
        cout << temp->data->data << " ";
        temp = temp->next;
    }
}

template <typename T>
TreeNode<T>* takeInput(){

    T rootData;
    cin >> rootData;

    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<T>* cur = q.front();
        q.pop();

        T l,r;
        cin >> l >> r;

        if(l != -1){
            cur->left = new TreeNode<T>(l);
            q.push(cur->left);
        }

        if(r != -1){
            cur->right = new TreeNode<T>(r);
            q.push(cur->right);
        }
    }

    return root;
}

int main(){

    TreeNode<int>* root = takeInput<int>();

    HeadAndTail<TreeNode<int>*> treeList = treeToList(root);

    printList(treeList);

    return 0;
}
