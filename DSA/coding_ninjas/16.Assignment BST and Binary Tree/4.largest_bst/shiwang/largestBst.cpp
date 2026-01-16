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

struct Info {
  bool isBst;
  int height;
  int mini;
  int maxi;

  Info(bool bst, int h, int minV, int maxV)
      : isBst(bst), height(h), mini(minV), maxi(maxV) {}
};

Info largestBst(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return Info(true, 0, INT_MAX, INT_MIN);
  }

  Info left = largestBst(root->left);
  Info right = largestBst(root->right);

  if (left.isBst && right.isBst && root->data > left.maxi &&
      root->data < right.mini) {
    return Info(true, 1 + max(left.height, right.height),
                min(left.mini, root->data), max(right.maxi, root->data));
  }

  return Info(false, max(left.height, right.height), min(left.mini, root->data),
              max(right.maxi, root->data));
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  Info largestBstHeight = largestBst(root);
  cout << largestBstHeight.height;
}