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

template <typename T> class Node {
public:
  T data;
  Node<T> *next;

  Node(T data) {
    this->data = data;
    this->next = NULL;
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

vector<Node<int> *> levelWiseLinkedList(BinaryTree<int> *root) {
  if (root == NULL)
    return {};

  vector<Node<int> *> linkedListArray;
  queue<BinaryTree<int> *> pendingNodes;

  pendingNodes.push(root);

  while (!pendingNodes.empty()) {
    int levelSize = pendingNodes.size();
    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    for (int i = 0; i < levelSize; i++) {
      BinaryTree<int> *front = pendingNodes.front();
      pendingNodes.pop();

      if (front->left)
        pendingNodes.push(front->left);
      if (front->right)
        pendingNodes.push(front->right);

      Node<int> *node = new Node<int>(front->data);
      if (head == NULL) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }
    linkedListArray.push_back(head);
  }
  return linkedListArray;
}

void printLL(Node<int> *head) {
  if (head == NULL)
    return;

  cout << head->data << " ";
  printLL(head->next);
}

int main() {
  BinaryTree<int> *root = takeInputLevelWise<int>();
  // 	levelOrderTraversal<int>(root);
  vector<Node<int> *> lwll = levelWiseLinkedList(root);

  for (int i = 0; i < lwll.size(); i++) {
    printLL(lwll[i]);
    cout << endl;
  }
}