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

template <typename T> void zigZagTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  stack<BinaryTree<T> *> s1, s2;
  s1.push(root);

  while (!s1.empty() || !s2.empty()) {
    while (!s1.empty()) {
      BinaryTree<T> *top = s1.top();
      s1.pop();

      cout << top->data << " ";
      if (top->left)
        s2.push(top->left);
      if (top->right)
        s2.push(top->right);
    }

    cout << endl;

    while (!s2.empty()) {
      BinaryTree<T> *top = s2.top();
      s2.pop();

      cout << top->data << " ";
      if (top->right)
        s1.push(top->right);
      if (top->left)
        s1.push(top->left);
    }
    cout << endl;
  }
}

int main() {
  BinaryTree<int> *root = takeInputLevelWise<int>();
  zigZagTraversal<int>(root);
}