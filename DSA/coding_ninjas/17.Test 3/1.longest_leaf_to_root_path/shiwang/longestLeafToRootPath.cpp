#include <climits>
#include <iostream>
#include <queue>
#include <vector>

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
  queue<BinaryTreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    int levelSize = pendingNodes.size();

    for (int i = 0; i < levelSize; i++) {
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
  }
  return root;
}

template <typename T> void levelOrderTraversal(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;

  queue<BinaryTreeNode<int> *> pendingNodes;

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
    cout << endl;
  }
}

int longestLeafToRootPathHelper(BinaryTreeNode<int> *root, vector<int> &path) {
  if (root == NULL)
    return 0;

  vector<int> leftPath;
  vector<int> rightPath;

  int left = longestLeafToRootPathHelper(root->left, leftPath);
  int right = longestLeafToRootPathHelper(root->right, rightPath);

  if (left >= right) {
    path = leftPath;
  } else {
    path = rightPath;
  }

  path.push_back(root->data);
  return 1 + max(left, right);
}

vector<int> longestLeafToRootPath(BinaryTreeNode<int> *root) {
  vector<int> longestPath;
  longestLeafToRootPathHelper(root, longestPath);
  return longestPath;
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  vector<int> longestPath = longestLeafToRootPath(root);
  for (int path : longestPath) {
    cout << path << endl;
  }
}