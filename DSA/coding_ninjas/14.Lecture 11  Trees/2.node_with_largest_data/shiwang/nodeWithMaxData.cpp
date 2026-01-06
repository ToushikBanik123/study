#include <iostream>
#include <queue>
#include <stack>
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

TreeNode<int> *takeInput() {
  int data;
  cout << "Enter Data:" << endl;
  cin >> data;
  cout << endl;

  TreeNode<int> *root = new TreeNode<int>(data);

  int children;
  cout << "Enter children:" << endl;
  cin >> children;

  for (int i = 0; i < children; i++) {
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }

  return root;
}

TreeNode<int> *takeInputByLevel() {
  int data;
  cin >> data;

  TreeNode<int> *root = new TreeNode<int>(data);
  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int children;
    cin >> children;
    for (int i = 0; i < children; i++) {
      cin >> data;
      TreeNode<int> *child = new TreeNode<int>(data);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

int nodeWithMaxData(TreeNode<int> *root) {
  if (root == NULL)
    return 0;

  int maxData = root->data;
  for (int i = 0; i < root->children.size(); i++) {
    maxData = max(maxData, nodeWithMaxData(root->children[i]));
  }

  return maxData;
}

// input by child:- 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0
// input by level:- 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
  TreeNode<int> *root = takeInputByLevel();
  cout << endl;
  cout << nodeWithMaxData(root);
}
