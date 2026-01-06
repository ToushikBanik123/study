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

void printTreeByLevel(TreeNode<int> *root) {
  if (root == NULL)
    return;

  queue<TreeNode<int> *> q;

  q.push(root);
  cout << root->data << " ";
  while (!q.empty()) {
    TreeNode<int> *front = q.front();
    q.pop();
    for (int i = 0; i < front->children.size(); i++) {
      cout << front->children[i]->data << " ";
      q.push(front->children[i]);
    }
  }
}

// pre-order traversal
void preOrderTraversal(TreeNode<int> *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++) {
    preOrderTraversal(root->children[i]);
  }
}

// post-order traversal
void postOrderTraversal(TreeNode<int> *root) {
  if (root == NULL)
    return;

  for (int i = 0; i < root->children.size(); i++) {
    postOrderTraversal(root->children[i]);
  }
  cout << root->data << " ";
}

// count Nodes
int countNodes(TreeNode<int> *root) {
  if (root == NULL)
    return 0;

  int ans = 1;
  for (int i = 0; i < root->children.size(); i++) {
    ans += countNodes(root->children[i]);
  }
  return ans;
}

// count leaf Nodes
int countLeafNodes(TreeNode<int> *root) {
  if (root == NULL)
    return 0;
  if (root->children.size() == 0)
    return 1;

  int ans = 0;
  for (int i = 0; i < root->children.size(); i++) {
    ans += countLeafNodes(root->children[i]);
  }

  return ans;
}

// height of Tree
int treeHeight(TreeNode<int> *root) {
  if (root == NULL)
    return 0;

  int ans = 0;
  for (int i = 0; i < root->children.size(); i++) {
    ans = max(ans, treeHeight(root->children[i]));
  }
  return ans + 1;
}

// print at level k
void printAtLevelK(TreeNode<int> *root, int k) {
  if (root == NULL)
    return;
  if (k == 0) {
    cout << root->data << " ";
    return;
  }

  for (int i = 0; i < root->children.size(); i++) {
    printAtLevelK(root->children[i], k - 1);
  }
}

// input by child:- 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0
// input by level:- 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
  TreeNode<int> *root = takeInputByLevel();
  cout << endl;
  preOrderTraversal(root);
  cout << endl;
  // 	printTreeByLevel(root);
  // 	cout << endl;
  // 	postOrderTraversal(root);
  cout << countNodes(root);
  cout << endl;
  cout << countLeafNodes(root);
  cout << endl;
  cout << treeHeight(root);
  cout << endl;
  printAtLevelK(root, 8);
}
