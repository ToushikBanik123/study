
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T> class BinaryTree {
public:
  int data;
  BinaryTree<T> *left;
  BinaryTree<T> *right;

  BinaryTree(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }

  ~BinaryTree() {
    delete left;
    delete right;
  }
};

template <typename T> BinaryTree<T> *takeInputByLevel() {
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

template <typename T> bool isNodePresent(BinaryTree<T> *root, int x) {
  if (root == NULL)
    return false;

  if (root->data == x)
    return true;
  if (isNodePresent(root->left, x))
    return true;
  if (isNodePresent(root->right, x))
    return true;
  return false;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
  BinaryTree<int> *root = takeInputByLevel<int>();
  int x;
  cin >> x;
  cout << ((isNodePresent<int>(root, x) == true) ? "true" : "false");
}