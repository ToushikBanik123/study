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

vector<pair<BinaryTreeNode<int> *, char>>
findNodePath(BinaryTreeNode<int> *root, int targetNode) {
  if (root == NULL)
    return {};

  if (root->data == targetNode) {
    return {{root, ' '}};
  }

  auto left = findNodePath(root->left, targetNode);
  if (left.size() != 0) {
    left.push_back({root, 'L'});
    return left;
  }
  auto right = findNodePath(root->right, targetNode);
  if (right.size() != 0) {
    right.push_back({root, 'R'});
    return right;
  }

  return {};
}

void printNodesAtDistanceK(BinaryTreeNode<int> *root, int distance, char path) {
  if (root == NULL)
    return;

  if (distance == 0) {
    cout << root->data << endl;
    return;
  }

  if (path == 'R') {
    printNodesAtDistanceK(root->left, distance - 1, ' ');
  } else if (path == 'L') {
    printNodesAtDistanceK(root->right, distance - 1, ' ');
  } else {
    printNodesAtDistanceK(root->left, distance - 1, ' ');
    printNodesAtDistanceK(root->right, distance - 1, ' ');
  }
}

void printNodesAtDistanceKFromNode(BinaryTreeNode<int> *root, int targetNode,
                                   int distance) {
  if (root == NULL)
    return;

  auto nodePath = findNodePath(root, targetNode);

  for (int i = 0; i < nodePath.size(); i++) {
    auto path = nodePath[i];
    printNodesAtDistanceK(path.first, distance - i, path.second);
  }
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  int targetNode, distance;
  cin >> targetNode >> distance;
  printNodesAtDistanceKFromNode(root, targetNode, distance);
}