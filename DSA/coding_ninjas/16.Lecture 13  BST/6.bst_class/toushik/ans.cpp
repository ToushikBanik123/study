#include<iostream>
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// BST CLASS
template <typename T>
class BST{
private:
    TreeNode<T>* rootNode;

public:
    BST(){
        rootNode = NULL;
    }

    ~BST(){
        deleteTree(rootNode);
    }

    bool searchNode(T data){
        return searchPrivate(data, rootNode);
    }

    void insertNode(T data){
        rootNode = insertPrivate(data, rootNode);
    }

    void deleteNode(T data){
        rootNode = deletePrivate(data, rootNode);
    }

private:

    // SEARCH
    bool searchPrivate(T data, TreeNode<T>* node){
        if(node == NULL) return false;

        if(node->data == data) return true;

        if(data < node->data)
            return searchPrivate(data, node->left);

        return searchPrivate(data, node->right);
    }

    // INSERT
    TreeNode<T>* insertPrivate(T data, TreeNode<T>* node){
        if(node == NULL)
            return new TreeNode<T>(data);

        if(data < node->data)
            node->left = insertPrivate(data, node->left);
        else
            node->right = insertPrivate(data, node->right);

        return node;
    }

    // DELETE
    TreeNode<T>* deletePrivate(T data, TreeNode<T>* node){
        if(node == NULL) return NULL;

        if(data < node->data){
            node->left = deletePrivate(data, node->left);
        }
        else if(data > node->data){
            node->right = deletePrivate(data, node->right);
        }
        else{
            // FOUND NODE

            // Case 1: No child
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }

            // Case 2: One child
            if(node->left == NULL){
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            }

            if(node->right == NULL){
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two children
            TreeNode<T>* successor = findSmallest(node->right);
            node->data = successor->data;
            node->right = deletePrivate(successor->data, node->right);
        }

        return node;
    }

    // FIND MIN
    TreeNode<T>* findSmallest(TreeNode<T>* node){
        while(node->left != NULL)
            node = node->left;

        return node;
    }

    // DELETE WHOLE TREE
    void deleteTree(TreeNode<T>* node){
        if(node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main(){
    BST<int> bst;

    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(15);
    bst.insertNode(12);
    bst.insertNode(18);

    bst.deleteNode(10);

    cout << bst.searchNode(10) << endl; // should print 0

    return 0;
}
