#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
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
			pendingNodes.push(front->left);
		}

		cin >> data;
		if(data != -1) {
			BinaryTreeNode<T>* right = new BinaryTreeNode<T>(data);
			front->right = right;
			pendingNodes.push(front->right);
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

			cout << front->data << " ";
			if(front->left) {
				pendingNodes.push(front->left);
			}

			if(front->right) {
				pendingNodes.push(front->right);
			}
		}
	}
}



void pairSum(BinaryTreeNode<int>* root, int sum) {
	if(root == NULL) return;

	unordered_set<int> nodesSet;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		int levelSize = pendingNodes.size();

		for(int i = 0; i < levelSize; i++) {
			BinaryTreeNode<int>* front = pendingNodes.front();
			pendingNodes.pop();

			nodesSet.insert(front->data);
			if(front->left) {
				pendingNodes.push(front->left);
			}

			if(front->right) {
				pendingNodes.push(front->right);
			}
		}
	}

	for(int x : nodesSet) {
		int y = sum - x;
		if(x < y && nodesSet.find(y) != nodesSet.end()) {
			cout << "{" << x << ", " << y << "}" <<endl;
		}
	}
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise<int>();
	int sum;
	cin >> sum;

	pairSum(root, sum);
}