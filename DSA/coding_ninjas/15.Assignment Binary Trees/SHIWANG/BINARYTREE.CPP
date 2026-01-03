#include <iostream>
#include <queue>
using namespace std;

template <typename T> class BinaryTree {
public:
  T data;
  BinaryTree<T> *left;
  BinaryTree<T> *right;

  BinaryTree(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }

  ~BinaryTree() {
    delete left;
    delete right;
  }
};

template <typename T> BinaryTree<T> *takeInput() {
  int data;
  cin >> data;
  if (data == -1)
    return NULL;

  BinaryTree<T> *root = new BinaryTree<T>(data);
  BinaryTree<T> *left = takeInput<T>();
  BinaryTree<T> *right = takeInput<T>();

  if (left != NULL)
    root->left = left;
  if (right != NULL)
    root->right = right;

  return root;
}

template <typename T> BinaryTree<T> *takeInputByLevel() {
  int data;
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

template <typename T> void preOrderTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  if (root->left != NULL)
    preOrderTraversal<T>(root->left);
  if (root->right != NULL)
    preOrderTraversal<T>(root->right);
}

template <typename T> void postOrderTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  if (root->left != NULL)
    postOrderTraversal<T>(root->left);
  if (root->right != NULL)
    postOrderTraversal<T>(root->right);
  cout << root->data << " ";
}

template <typename T> void levelOrderTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  queue<BinaryTree<T> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty()) {
    BinaryTree<T> *front = pendingNodes.front();
    pendingNodes.pop();

    cout << front->data << " ";

    if (front->left != NULL) {
      pendingNodes.push(front->left);
    }
    if (front->right != NULL) {
      pendingNodes.push(front->right);
    }
  }
}

template <typename T> void inOrderTraversal(BinaryTree<T> *root) {
  if (root == NULL)
    return;

  if (root->left != NULL)
    inOrderTraversal<T>(root->left);
  cout << root->data << " ";
  if (root->right != NULL)
    inOrderTraversal<T>(root->right);
}

int main() {
  // 	BinaryTree<int>* root = takeInput<int>();
  BinaryTree<int> *root = takeInputByLevel<int>();
  preOrderTraversal<int>(root);
  cout << endl;
  postOrderTraversal<int>(root);
  cout << endl;
  levelOrderTraversal<int>(root);
  cout << endl;
  inOrderTraversal<int>(root);
  cout << endl;
}
