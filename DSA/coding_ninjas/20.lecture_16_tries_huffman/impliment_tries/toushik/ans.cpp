#include <iostream>
#include<string>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode ** child;
    bool isEnd;
    TrieNode(char data){
        this->data = data;
        this->child = new TrieNode*[26]{nullptr};
        this->isEnd = false;
    }
};

class Trie{
    private:
    TrieNode * rootNode;

    void insertWordHelper(string word,TrieNode * rootNode){
        if(word.empty()){
            rootNode->isEnd = 1;
            return;
        }

        int dataIndex = word[0] - 'a';

        TrieNode * child;

        if(rootNode->child[dataIndex] == nullptr){
            child = new TrieNode(word[0]);
            rootNode->child[dataIndex] = child;
        }else{
            child = rootNode->child[dataIndex];
        }
        
        insertWordHelper(word.substr(1),child);
    }

    bool serchWordHelper(string word, TrieNode * rootNode){
        if(word.empty()){
            return rootNode->isEnd;
        }
        int charIndex = word[0] - 'a';
        if(rootNode->child[charIndex] == nullptr){
            return 0;
        }
        return serchWordHelper(word.substr(1),rootNode->child[charIndex]);
    }

    void removeWordHelper(string word,TrieNode * rootNode){
        if(word.empty()){
            rootNode->isEnd = 0;
            return;
        }

        int dataIndex = word[0] - 'a';

        TrieNode * child;

        if(rootNode->child[dataIndex] == nullptr){
            return;
        }else{
            child = rootNode->child[dataIndex];
        }
        
        removeWordHelper(word.substr(1),child);

        if(!child->isEnd){
            for(int i = 0; i < 26; i++){
                if(child->child[i] != nullptr){
                    return;
                }
            }
            delete child;
            rootNode->child[dataIndex] = nullptr; 
        }
    }

    public:
    Trie(){
        rootNode = new TrieNode('\0');
    }

    void insertWord(string word){
        insertWordHelper(word,rootNode);
    }

    bool serchWord(string word){
        return serchWordHelper(word,rootNode);
    }

    void removeWord(string word){
        removeWordHelper(word,rootNode);
    }
};

int main(){
    Trie t;
    t.insertWord("apple");
    t.insertWord("app");
    
    cout << t.serchWord("apple") << endl;  // 1
    cout << t.serchWord("app") << endl;    // 1
    cout << t.serchWord("ap") << endl;     // 0
    
    t.removeWord("apple");
    cout << t.serchWord("apple") << endl;  // 0
    cout << t.serchWord("app") << endl;    // 1 (should still exist)
    
    return 0;
}