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

pair<int, int> nodePair1;
pair<int, int> nodePair2;

void findParentAndDepth(BinaryTreeNode<int> *root, int node1, int node2,
                        int depth, int parent) {
  if (root == NULL)
    return;

  if (root->data == node1 && nodePair1.first == INT_MIN &&
      nodePair1.second == INT_MIN) {
    nodePair1 = {parent, depth};
  }
  if (root->data == node2 && nodePair2.first == INT_MIN &&
      nodePair2.second == INT_MIN) {
    nodePair2 = {parent, depth};
  }

  findParentAndDepth(root->left, node1, node2, depth + 1, root->data);
  findParentAndDepth(root->right, node1, node2, depth + 1, root->data);
}

bool checkCousins(BinaryTreeNode<int> *root, int node1, int node2) {
  nodePair1 = {INT_MIN, INT_MIN};
  nodePair2 = {INT_MIN, INT_MIN};

  findParentAndDepth(root, node1, node2, 0, INT_MIN);

  if (nodePair1.second == INT_MIN || nodePair2.second == INT_MIN ||
      (nodePair2.second != nodePair1.second) ||
      (nodePair1.first == nodePair2.first))
    return false;
  return true;
}

bool checkCousinsBFS(BinaryTreeNode<int> *root, int node1, int node2) {
  if (root == NULL)
    return false;

  queue<pair<BinaryTreeNode<int> *, BinaryTreeNode<int> *>> pendingNodes;
  pendingNodes.push({root, NULL});

  while (!pendingNodes.empty()) {
    int levelSize = pendingNodes.size();

    bool foundNode1 = false;
    bool foundNode2 = false;
    BinaryTreeNode<int> *parent1 = NULL;
    BinaryTreeNode<int> *parent2 = NULL;

    for (int i = 0; i < levelSize; i++) {
      auto front = pendingNodes.front();
      pendingNodes.pop();

      BinaryTreeNode<int> *parent = front.second;
      BinaryTreeNode<int> *node = front.first;

      if (node->data == node1) {
        foundNode1 = true;
        parent1 = parent;
      }

      if (node->data == node2) {
        foundNode2 = true;
        parent2 = parent;
      }

      if (node->left) {
        pendingNodes.push({node->left, node});
      }

      if (node->right) {
        pendingNodes.push({node->right, node});
      }
    }

    if (foundNode2 && foundNode1)
      return parent1 != parent2;

    if (foundNode1 || foundNode2)
      return false;
  }

  return false;
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  int node1, node2;
  cin >> node1 >> node2;
  cout << checkCousinsBFS(root, node1, node2);
}