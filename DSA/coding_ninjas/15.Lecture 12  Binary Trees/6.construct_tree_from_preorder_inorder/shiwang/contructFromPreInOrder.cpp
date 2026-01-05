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

BinaryTree<int> *constructBinaryTreePreInOrder(vector<int> &inOrder,
                                               vector<int> &preOrder,
                                               int inStart, int inEnd,
                                               int preStart, int preEnd) {
  if (inStart > inEnd || preStart > preEnd) {
    return NULL;
  }

  int inRootIdx = 0;
  for (int i = 0; i <= inEnd; i++) {
    if (inOrder[i] == preOrder[preStart]) {
      inRootIdx = i;
      break;
    }
  }

  int leftSubTree = inRootIdx - inStart;
  int preLeftEndIdx = preStart + leftSubTree;

  BinaryTree<int> *left = constructBinaryTreePreInOrder(
      inOrder, preOrder, inStart, inRootIdx - 1, preStart + 1, preLeftEndIdx);
  BinaryTree<int> *right = constructBinaryTreePreInOrder(
      inOrder, preOrder, inRootIdx + 1, inEnd, preLeftEndIdx + 1, preEnd);

  BinaryTree<int> *root = new BinaryTree<int>(inOrder[inRootIdx]);
  root->left = left;
  root->right = right;

  return root;
}

int main() {
  // 	BinaryTree<int>* root = takeInputLevelWise<int>();
  int n;
  cin >> n;

  vector<int> preOrder;
  vector<int> inOrder;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    preOrder.push_back(data);
  }
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    inOrder.push_back(data);
  }

  BinaryTree<int> *root =
      constructBinaryTreePreInOrder(inOrder, preOrder, 0, n - 1, 0, n - 1);
  levelOrderTraversal(root);
}