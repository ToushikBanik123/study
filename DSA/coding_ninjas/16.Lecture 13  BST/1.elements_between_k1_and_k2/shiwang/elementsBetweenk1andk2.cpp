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

void printBetweenK1andK2(BinaryTreeNode<int> *root, int k1, int k2) {
  if (root == NULL)
    return;

  printBetweenK1andK2(root->left, k1, k2);
  if (root->data >= k1 && root->data <= k2)
    cout << root->data << " ";
  printBetweenK1andK2(root->right, k1, k2);
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise();
  // 	levelOrderTraversal(root);
  int k1, k2;
  cin >> k1 >> k2;
  // cout << checkNodeExists(root, data);
  printBetweenK1andK2(root, k1, k2);
}
