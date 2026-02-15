#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

template <typename T>
TreeNode<T>* takeInput() {
    T rootData;
    cin >> rootData;

    if (rootData == -1) return NULL;

    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();

        T leftData, rightData;
        cin >> leftData >> rightData;

        if (leftData != -1) {
            curr->left = new TreeNode<T>(leftData);
            q.push(curr->left);
        }

        if (rightData != -1) {
            curr->right = new TreeNode<T>(rightData);
            q.push(curr->right);
        }
    }

    return root;
}

void printPairSum(TreeNode<int>* root, int sum, unordered_set<int>& s) {
    if (root == NULL) return;

    int need = sum - root->data;

    if (s.count(need)) {
        cout << min(root->data, need) << " "
             << max(root->data, need) << endl;
        s.erase(need);   // avoid duplicate pairs
    } else {
        s.insert(root->data);
    }

    printPairSum(root->left, sum, s);
    printPairSum(root->right, sum, s);
}

int main() {
    TreeNode<int>* root = takeInput<int>();

    int x;
    cin >> x;

    unordered_set<int> s;
    printPairSum(root, x, s);

    delete root;
    return 0;
}
