#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(T data) {
		this->data = data;
		this->next = NULL;
	}
};

template <typename T>
BinaryTreeNode<T>* takeInputLevelWise() {
	int data;
	cin >> data;

	if(data == -1) return NULL;

	BinaryTreeNode<T>* root = new BinaryTreeNode<T>(data);
	queue<BinaryTreeNode<T>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		BinaryTreeNode<T>* front = pendingNodes.front();
		pendingNodes.pop();

		cin >> data;
		if(data != -1) {
			BinaryTreeNode<T>* left = new BinaryTreeNode<T>(data);
			front->left = left;
			pendingNodes.push(left);
		}

		cin >> data;
		if(data != -1) {
			BinaryTreeNode<T>* right = new BinaryTreeNode<T>(data);
			front->right = right;
			pendingNodes.push(right);
		}
	}
	return root;
}

template <typename T>
void levelOrderTraversal(BinaryTreeNode<T>* root) {
	if(root == NULL) return;

	queue<BinaryTreeNode<T>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		int levelSize = pendingNodes.size();

		for(int i = 0; i < levelSize; i++) {
			BinaryTreeNode<T>* front = pendingNodes.front();
			pendingNodes.pop();

			cout << front->data <<" ";
			if(front->left) pendingNodes.push(front->left);
			if(front->right) pendingNodes.push(front->right);
		}
		cout << endl;
	}
}

// pair.first = head
// pair.second = tail
pair<Node<int>*, Node<int>*> constructLLFromBst(BinaryTreeNode<int>* root) {
	if(root == NULL) return {NULL, NULL};

	auto left = constructLLFromBst(root->left);
	auto right = constructLLFromBst(root->right);

	Node<int>* node = new Node<int>(root->data);
	if(left.first == NULL) {
		left.first = node;
		left.second = node;
	} else {
		left.second->next = node;
		left.second = node;
	}

	left.second->next = right.first;
	if(right.second == NULL) {
		right.second = left.second;
	}
	return {left.first, right.second};
}

void printLL(Node<int>* head) {
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise<int>();
	Node<int>* head = constructLLFromBst(root).first;
	
	printLL(head);
}