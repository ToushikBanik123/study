#include <climits>
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
      pendingNodes.push(left);
    }
    cin >> data;
    if (data != -1) {
      BinaryTreeNode<T> *right = new BinaryTreeNode<T>(data);
      front->right = right;
      pendingNodes.push(right);
    }
  }
  return root;
}

template <typename T>
BinaryTreeNode<T> *createInsertDuplicateNode(BinaryTreeNode<T> *root) {
  if (root == NULL)
    return NULL;

  queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty()) {
    BinaryTreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();

    BinaryTreeNode<T> *duplicate = new BinaryTreeNode<T>(front->data);
    if (front->left) {
      pendingNodes.push(front->left);
      duplicate->left = front->left;
    }
    front->left = duplicate;
    if (front->right) {
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
    cout << endl;
  }
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  levelOrderTraversal(root);
  root = createInsertDuplicateNode<int>(root);
  levelOrderTraversal(root);

  return 0;
}
