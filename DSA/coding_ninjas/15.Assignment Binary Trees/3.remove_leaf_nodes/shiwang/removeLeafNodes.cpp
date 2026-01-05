#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

template <typename T> class BinaryTree {
public:
  T data;
  BinaryTree<T> *left;
  BinaryTree<T> *right;

  BinaryTree(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

template <typename T> BinaryTree<T> *takeInputLevelWise() {
  T data;
  cin >> data;

  if (data == -1)
    return NULL;

  BinaryTree<T> *root = new BinaryTree<T>(data);
  queue<BinaryTree<T> *> pendingNodes;

  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTree<T> *front = pendingNodes.front();
    pendingNodes.pop();

    cin >> data;
    if (data != -1) {
      BinaryTree<T> *left = new BinaryTree<T>(data);
      front->left = left;
      pendingNodes.push(left);
    }

    cin >> data;
    if (data != -1) {
      BinaryTree<T> *right = new BinaryTree<T>(data);
      front->right = right;
      pendingNodes.push(right);
    }
  }

  return root;
}

template <typename T> void levelOrderTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  queue<BinaryTree<T> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty()) {

    int levelSize = pendingNodes.size();

    for (int i = 0; i < levelSize; i++) {
      BinaryTree<T> *front = pendingNodes.front();
      pendingNodes.pop();

      cout << front->data << " ";

      if (front->left != NULL)
        pendingNodes.push(front->left);
      if (front->right != NULL)
        pendingNodes.push(front->right);
    }
    cout << endl;
  }
}

BinaryTree<int> *removeLeafNodes(BinaryTree<int> *root) {
  if (root == NULL)
    return NULL;

  if (root->left == NULL && root->right == NULL) {
    delete root;
    return NULL;
  }

  BinaryTree<int> *left = removeLeafNodes(root->left);
  BinaryTree<int> *right = removeLeafNodes(root->right);

  root->left = left;
  root->right = right;
  return root;
}

int main() {
  BinaryTree<int> *root = takeInputLevelWise<int>();
  levelOrderTraversal<int>(root);
  root = removeLeafNodes(root);
  levelOrderTraversal<int>(root);
}