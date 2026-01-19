#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}
};

template <typename T>
TreeNode<T>* takeInput() {
	int data;
	cin >> data;

	if(data == 0) return NULL;

	TreeNode<T>* root = new TreeNode<T>(data);
	queue<TreeNode<T>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		TreeNode<T>* front = pendingNodes.front();
		pendingNodes.pop();

		int children;
		cin >> children;

		for(int i = 0; i < children; i++) {
			cin >> data;
			TreeNode<T>* child = new TreeNode<T>(data);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

template <typename T>
void print(TreeNode<T>* root) {
	if(root == NULL) return;

	queue<TreeNode<T>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		int levelSize = pendingNodes.size();

		for(int i = 0; i < levelSize; i++) {
			TreeNode<T>* front = pendingNodes.front();
			pendingNodes.pop();

			cout << front->data << " ";

			for(int i = 0; i < front->children.size(); i++) {
				pendingNodes.push(front->children[i]);
			}
		}
		cout << endl;
	}
}

TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
	if(root == NULL) return NULL;

	if(root->children.size() == 0) {
		delete root;
		return NULL;
	}

	vector<TreeNode<int>*> newChildren;

	for(int i = 0; i < root->children.size(); i++) {
		TreeNode<int>* node = removeLeafNodes(root->children[i]);
		if(node != NULL) {
			newChildren.push_back(node);
		}
	}

	root->children = newChildren;
	return root;
}

int main() {
	TreeNode<int>* root = takeInput<int>();
	print<int>(root);
    root = removeLeafNodes(root);
    print(root);
}
