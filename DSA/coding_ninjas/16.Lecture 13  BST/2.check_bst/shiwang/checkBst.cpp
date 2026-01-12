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

			cout << front->data <<  " ";
			if(front->left) {
				pendingNodes.push(front->left);
			}
			if(front->right) {
				pendingNodes.push(front->right);
			}
		}
		cout << endl;
	}
}

bool checkBst(BinaryTreeNode<int>* root, int& mini, int& maxi) {
	if(root == NULL) return true;

	if(mini >= root->data || root->data >= maxi) return false;

	return checkBst(root->left, mini, root->data) && checkBst(root->right, root->data, maxi);
}

bool checkBst(BinaryTreeNode<int>* root, int& prev) {
	if(root == NULL) return true;

	if(!checkBst(root->left, prev)) return false;

	if(root->data <= prev) return false;
	prev = root->data;

	if(!checkBst(root->right, prev)) return false;

	return true;
}

bool checkBst(BinaryTreeNode<int>* root) {
	if(root == NULL) return true;
	int prev = INT_MIN;
	int mini = INT_MIN;
	int maxi = INT_MAX;
	return checkBst(root, mini, maxi);
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    cout << checkBst(root);
}