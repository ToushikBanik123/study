#include <iostream>
#include <queue>
#include <vector>

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


void replaceDataByDepthValue(TreeNode<int> *root, int k = 0) {
  if (root == NULL)
    return;

  for (int i = 0; i < root->children.size(); i++) {
    replaceDataByDepthValue(root->children[i], k + 1);
  }

  root->data = k;
}
// input by child:- 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0
// input by level:- 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
  TreeNode<int> *root1 = takeInput<int>();
  TreeNode<int> *root2 = takeInputByLevel<int>();

  replaceDataByDepthValue(root1);

  printTreeByLevel(root1);
  cout << endl;
  printTreeByLevel(root2);
  cout << endl;
}