#include <iostream>
#include <queue>
#include <stack>
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

void moveLeft(BinaryTreeNode<int> *root,
              stack<BinaryTreeNode<int> *> &smallest) {
  while (root != NULL) {
    smallest.push(root);
    root = root->left;
  }
}

void moveRight(BinaryTreeNode<int> *root,
               stack<BinaryTreeNode<int> *> &largest) {
  while (root != NULL) {
    largest.push(root);
    root = root->right;
  }
}

void print(int small, int large) { cout << small << " " << large << endl; }

void pairSumBst(BinaryTreeNode<int> *root, int target) {
  if (root == NULL)
    return;

  stack<BinaryTreeNode<int> *> smallest;
  stack<BinaryTreeNode<int> *> largest;

  moveLeft(root, smallest);
  moveRight(root, largest);

  while ((!smallest.empty() && !largest.empty()) &&
         smallest.top()->data < largest.top()->data) {
    BinaryTreeNode<int> *smallestTop = smallest.top();
    BinaryTreeNode<int> *largestTop = largest.top();
    if (smallestTop->data + largestTop->data == target) {
      print(smallestTop->data, largestTop->data);
      smallest.pop();
      moveLeft(smallestTop->right, smallest);
      largest.pop();
      moveRight(largestTop->left, largest);
    } else if (smallestTop->data + largestTop->data > target) {
      largest.pop();
      moveRight(largestTop->left, largest);
    } else {
      smallest.pop();
      moveLeft(smallestTop->right, smallest);
    }
  }
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  int target;
  cin >> target;
  pairSumBst(root, target);
}