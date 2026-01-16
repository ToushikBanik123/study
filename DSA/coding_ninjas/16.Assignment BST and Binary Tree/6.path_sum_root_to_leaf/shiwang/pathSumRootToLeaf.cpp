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

void printPathSumRootToLeaf(BinaryTreeNode<int> *root, vector<int> &path,
                            int target) {
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL && target - root->data == 0) {
    path.push_back(root->data);
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << " ";
    }
    cout << endl;
    path.pop_back();
    return;
  }

  path.push_back(root->data);
  printPathSumRootToLeaf(root->left, path, target - root->data);
  printPathSumRootToLeaf(root->right, path, target - root->data);
  path.pop_back();
}

void printPathSumRootToLeaf(BinaryTreeNode<int> *root, int target) {
  vector<int> path;
  printPathSumRootToLeaf(root, path, target);
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  // 	levelOrderTraversal<int>(root);
  int target;
  cin >> target;
  printPathSumRootToLeaf(root, target);
}