#include <bits/stdc++.h>
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
      pendingNodes.push(front->left);
    }

    cin >> data;
    if (data != -1) {
      BinaryTreeNode<T> *right = new BinaryTreeNode<T>(data);
      front->right = right;
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
  }
}

void findAncestors(BinaryTreeNode<int> *root, int data, vector<int> &ancestor) {
  if (root == NULL)
    return;

  if (root->data == data) {
    ancestor.push_back(root->data);
    return;
  }
  findAncestors(root->left, data, ancestor);
  if (ancestor.size() > 0) {
    ancestor.push_back(root->data);
    return;
  }
  findAncestors(root->right, data, ancestor);
  if (ancestor.size() > 0) {
    ancestor.push_back(root->data);
    return;
  }
}

int LCA(BinaryTreeNode<int> *root, int data1, int data2) {
  vector<int> ancestorsNode1;
  vector<int> ancestorsNode2;

  findAncestors(root, data1, ancestorsNode1);
  findAncestors(root, data2, ancestorsNode2);

  int lca = -1;

  if (ancestorsNode1.size() > 0 && ancestorsNode2.size() > 0) {
    int i = ancestorsNode1.size() - 1;
    int j = ancestorsNode2.size() - 1;
    while (i >= 0 && j >= 0) {
      if (ancestorsNode1[i] == ancestorsNode2[j]) {
        lca = ancestorsNode1[i];
      } else {
        break;
      }
      i--;
      j--;
    }
  }

  if (ancestorsNode1.size() > 0 && ancestorsNode2.size() == 0) {
    lca = ancestorsNode1[0];
  }

  if (ancestorsNode2.size() > 0 && ancestorsNode1.size() == 0) {
    lca = ancestorsNode2[0];
  }

  return lca;
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise<int>();
  int data1, data2;
  cin >> data1 >> data2;
  cout << LCA(root, data1, data2);
}