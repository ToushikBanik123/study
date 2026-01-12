#include <bits/stdc++.h>
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

template <typename T> BinaryTreeNode<T> *takeInputLevelWise() {
  int data;
  cin >> data;

  if (data == -1)
    return NULL;

  BinaryTreeNode<T> *root = new BinaryTreeNode<T>(data);
  queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty()) {
    BinaryTreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();

    cin >> data;
    if (data != -1) {
      BinaryTreeNode<T> *left = new BinaryTreeNode<T>(data);
      front->left = left;
      pendingNodes.push(front->left);
    }

    cin >> data;
    if (data != -1) {
      BinaryTreeNode<T> *right = new BinaryTreeNode<T>(data);
      front->right = right;
      pendingNodes.push(front->right);
    }
  }
  return root;
}

template <typename T> void levelOrderTraversal(BinaryTreeNode<T> *root) {
  if (root == NULL)
    return;

  queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty()) {
    int levelSize = pendingNodes.size();

    for (int i = 0; i < levelSize; i++) {
      BinaryTreeNode<T> *front = pendingNodes.front();
      pendingNodes.pop();

      cout << front->data << " ";
      if (front->left) {
        pendingNodes.push(front->left);
      }

      if (front->right) {
        pendingNodes.push(front->right);
      }
    }
  }
}

int LCAOfBST(BinaryTreeNode<int> *root, int data1, int data2) {
  if (root == NULL)
    return -1;

  if (root->data == data1 || root->data == data2) {
    return root->data;
  }

  if (root->data > data1 && root->data > data2) {
    return LCAOfBST(root->left, data1, data2);
  } else if (root->data < data1 && root->data < data2) {
    return LCAOfBST(root->right, data1, data2);
  } else {
    return root->data;
  }
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  int data1, data2;
  cin >> data1 >> data2;
  cout << LCAOfBST(root, data1, data2);
}