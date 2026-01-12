#include <iostream>
#include <queue>
using namespace std;

template <typename T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

BinaryTreeNode<int> *takeInputLevelWise() {
  int data;
  cin >> data;

  if (data == -1) {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
  queue<BinaryTreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();

    cin >> data;
    if (data != -1) {
      BinaryTreeNode<int> *left = new BinaryTreeNode<int>(data);
      front->left = left;
      pendingNodes.push(left);
    }
    cin >> data;
    if (data != -1) {
      BinaryTreeNode<int> *right = new BinaryTreeNode<int>(data);
      front->right = right;
      pendingNodes.push(right);
    }
  }
  return root;
}

void levelOrderTraversal(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;

  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    int levelSize = pendingNodes.size();

    for (int i = 0; i < levelSize; i++) {
      BinaryTreeNode<int> *front = pendingNodes.front();
      pendingNodes.pop();

      cout << front->data << " ";
      if (front->left) {
        pendingNodes.push(front->left);
      }
      if (front->right) {
        pendingNodes.push(front->right);
      }
    }
    cout << endl;
  }
}

bool checkNodeExists(BinaryTreeNode<int> *root, int data) {
  if (root == NULL)
    return false;

  if (root->data == data)
    return true;
  else if (root->data > data)
    return checkNodeExists(root->left, data);
  else
    return checkNodeExists(root->right, data);
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise();
  // 	levelOrderTraversal(root);
  int data;
  cin >> data;
  cout << checkNodeExists(root, data);
}
