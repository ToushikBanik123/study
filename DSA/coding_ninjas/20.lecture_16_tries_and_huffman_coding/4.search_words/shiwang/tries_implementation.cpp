#include<iostream>
using namespace std;

class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data) {
		this->data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Tries {
	TrieNode* root;

	void insert(TrieNode* root, string word, int pos) {
		if(pos == word.length()) {
			root->isTerminal = true;
			return;
		}

		int idx = word[pos] - 'a';
		TrieNode* child;

		if(root->children[idx] != NULL) {
			child = root->children[idx];
		} else {
			child = new TrieNode(word[pos]);
			root->children[idx] = child;
		}

		insert(child, word, pos + 1);
	}

	bool search(TrieNode* root, string word, int pos) {
		if(pos == word.length()) {
			return root->isTerminal;
		}

		int idx = word[pos] - 'a';
		TrieNode* child;

		if(root->children[idx] != NULL) {
			child = root->children[idx];
		} else {
			return false;
		}

		return search(child, word, pos + 1);
	}

	void deleteWord(TrieNode* root, string word, int pos) {
		if(pos == word.length()) {
			root->isTerminal = false;
			return;
		}

		int idx = word[pos] - 'a';
		TrieNode* child;

		if(root->children[idx] != NULL) {
			child = root->children[idx];
		} else {
			return;
		}

		deleteWord(child, word, pos + 1);

		if(!child->isTerminal && checkNULL(child->children)) {
			delete child;
			root->children[idx] = NULL;
		}
	}

	bool checkNULL(TrieNode** children) {
		for(int i = 0; i < 26; i++) {
			if(children[i] != NULL) return false;
		}
		return true;
	}
public:
	Tries() {
		root = new TrieNode('\0');
	}

	void insert(string word) {
		insert(root, word, 0);
	}
	bool search(string word) {
		return search(root, word, 0);
	}
	void deleteWord(string word) {
		deleteWord(root, word, 0);
	}
};

int main() {
	Tries dict;

	dict.insert("are");
	dict.insert("arm");
	dict.insert("but");
	dict.insert("blur");
	dict.insert("block");

	cout << dict.search("arm") << endl;
	dict.deleteWord("arm");
	cout << dict.search("arm") << endl;

	cout << dict.search("but") << endl;
	cout << dict.search("blur") << endl;
	cout << dict.search("block") << endl;

	dict.deleteWord("blur");
	cout << dict.search("blur") << endl;
}