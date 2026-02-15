#include <iostream>
using namespace std;

class SuffixTrieNode {
public:
  char data;
  SuffixTrieNode **children;

  SuffixTrieNode(char data) {
    this->data = data;
    children = new SuffixTrieNode *[26];
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
};

class SuffixTries {
  SuffixTrieNode *root;

  void insert(SuffixTrieNode *root, string word, int pos) {
    if (pos == word.length())
      return;

    int idx = word[pos] - 'a';
    SuffixTrieNode *child;

    if (root->children[idx] != NULL) {
      child = root->children[idx];
    } else {
      child = new SuffixTrieNode(word[pos]);
      root->children[idx] = child;
    }

    insert(child, word, pos + 1);
  }

  bool search(SuffixTrieNode *root, string word, int pos) {
    if (pos == word.length())
      return true;

    int idx = word[pos] - 'a';
    SuffixTrieNode *child;

    if (root->children[idx] != NULL) {
      child = root->children[idx];
    } else {
      return false;
    }

    return search(child, word, pos + 1);
  }

public:
  SuffixTries() { root = new SuffixTrieNode('\0'); }

  void insert(string word) {
    for (int i = 0; i < word.length(); i++) {
      insert(root, word, i);
    }
  }

  bool search(string word) { return search(root, word, 0); }
};

int main() {
  // 	Tries dict;
  SuffixTries dict;

  dict.insert("are");
  dict.insert("arm");
  dict.insert("but");
  dict.insert("blur");
  dict.insert("block");

  cout << dict.search("arm") << endl;
  // 	dict.deleteWord("arm");
  cout << dict.search("arm") << endl;

  cout << dict.search("but") << endl;
  cout << dict.search("blur") << endl;
  cout << dict.search("block") << endl;

  // 	dict.deleteWord("blur");
  cout << dict.search("blur") << endl;
  cout << dict.search("bl") << endl;
  cout << dict.search("lock") << endl;
}

i have one question should i add delete functionality in the suffix trie