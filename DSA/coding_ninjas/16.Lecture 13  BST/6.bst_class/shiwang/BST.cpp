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

template <typename T> class BST {
  BinaryTreeNode<T> *root;

  BinaryTreeNode<T> *deleteData(T data, BinaryTreeNode<T> *node) {
    if (node == NULL)
      return NULL;

    if (node->data > data) {
      node->left = deleteData(data, node->left);
      return node;
    } else if (node->data < data) {
      node->right = deleteData(data, node->right);
      return node;
    } else {
      if (node->left == NULL && node->right == NULL) {
        delete node;
        return NULL;
      }

      if (node->left != NULL && node->right == NULL) {
        BinaryTreeNode<T> *temp = node->left;
        delete node;
        return temp;
      }

      if (node->left == NULL && node->right != NULL) {
        BinaryTreeNode<T> *temp = node->right;
        delete node;
        return temp;
      }

      BinaryTreeNode<T> *minNode = node->right;
      while (minNode->left != NULL) {
        minNode = minNode->left;
      }
      T rightMin = minNode->data;
      node->data = rightMin;
      node->right = deleteData(rightMin, node->right);
      return node;
    }
  }

  BinaryTreeNode<T> *insert(T data, BinaryTreeNode<T> *node) {
    if (node == NULL) {
      BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
      return newNode;
    }

    if (node->data > data) {
      node->left = insert(data, node->left);
    } else if (node->data < data) {
      node->right = insert(data, node->right);
    }

    return node;
  }

  bool search(T data, BinaryTreeNode<T> *node) {
    if (node == NULL)
      return false;

    if (node->data == data)
      return true;
    else if (node->data > data)
      return search(data, node->left);
    else
      return search(data, node->right);
  }

  void deleteTree(BinaryTreeNode<T> *node) {
    if (node == NULL)
      return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }

public:
  BST() { this->root = NULL; }

  void deleteData(T data) {
    this->root = deleteData(data, this->root);
    return;
  }

  void insert(T data) {
    this->root = insert(data, this->root);
    return;
  }

  bool search(T data) { return search(data, this->root); }

  void printBST() {
    levelOrderTraversal(this->root);
    return;
  }

  ~BST() { deleteTree(root); }
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
  BST<int> bst;

  // Insert elements
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  cout << "Inorder after insertion: ";
  bst.printBST();
  // Expected: 20 30 40 50 60 70 80

  // Search tests
  cout << "Search 40: " << bst.search(40) << endl; // 1 (true)
  cout << "Search 90: " << bst.search(90) << endl; // 0 (false)

  // Delete leaf node
  bst.deleteData(20);
  cout << "After deleting 20 (leaf): ";
  bst.printBST();
  // Expected: 30 40 50 60 70 80

  // Delete node with one child
  bst.deleteData(30);
  cout << "After deleting 30 (one child): ";
  bst.printBST();
  // Expected: 40 50 60 70 80

  // Delete node with two children
  bst.deleteData(50);
  cout << "After deleting 50 (two children): ";
  bst.printBST();
  // Expected: 40 60 70 80

  // Delete root until empty
  bst.deleteData(40);
  bst.deleteData(60);
  bst.deleteData(70);
  bst.deleteData(80);

  cout << "After deleting all nodes: ";
  bst.printBST(); // empty line

  return 0;
}
