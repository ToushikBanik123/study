#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<queue>
using namespace std;

template <typename T> class TreeNode {
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(T data) { this->data = data; }

  ~TreeNode() {
    for (int i = 0; i < children.size(); i++) {
      delete children[i];
    }
  }
};

template <typename T> TreeNode<T> *takeInput() {
  int data;
  cin >> data;

  TreeNode<T> *root = new TreeNode<T>(data);

  int children;
  cin >> children;

  for (int i = 0; i < children; i++) {
    TreeNode<T> *child = takeInput<T>();
    root->children.push_back(child);
  }

  return root;
}

template <typename T> TreeNode<T> *takeInputByLevel() {
  int data;
  cin >> data;

  TreeNode<T> *root = new TreeNode<T>(data);
  queue<TreeNode<T> *> pendingNodes;

  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    TreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();

    int children;
    cin >> children;

    for (int i = 0; i < children; i++) {
      cin >> data;
      TreeNode<T> *child = new TreeNode<T>(data);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }

  return root;
}

template <typename T> void printTreeByLevel(TreeNode<T> *root) {
  if (root == NULL)
    return;

  queue<TreeNode<T> *> pendingNodes;
  pendingNodes.push(root);
  cout << root->data << " ";

  while (!pendingNodes.empty()) {
    TreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();
    for (int i = 0; i < front->children.size(); i++) {
      cout << front->children[i]->data << " ";
      pendingNodes.push(front->children[i]);
    }
  }
}

template <typename T> void preOrderTraversal(TreeNode<T> *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++) {
    preOrderTraversal(root->children[i]);
  }
}

template <typename T> void postOrderTraversal(TreeNode<T> *root) {
  if (root == NULL)
    return;

  for (int i = 0; i < root->children.size(); i++) {
    postOrderTraversal(root->children[i]);
  }
  cout << root->data << " ";
}


pair<int, int> secondLargest(TreeNode<int> *root) {
  if (root == NULL)
    return {INT_MIN, INT_MIN};

  int largest = root->data;
  int secondLarge = INT_MIN;

  for (int i = 0; i < root->children.size(); i++) {
    pair<int, int> num2 = secondLargest(root->children[i]);

    if (num2.first > largest) {
      secondLarge = largest;
      largest = num2.first;
    } else if (num2.first < largest && num2.first > secondLarge) {
      secondLarge = num2.first;
    }

    if (num2.second < largest && num2.second > secondLarge) {
      secondLarge = num2.second;
    }
  }

  return {largest, secondLarge};
}

// input by child:- 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0
// input by level:- 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
  TreeNode<int> *root2 = takeInputByLevel<int>();

  cout << secondLargest(root2).second;
}