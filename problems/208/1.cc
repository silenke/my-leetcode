#include "..\..\leetcode.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        Trie* root = this;
        for (char c : word) {
            int i = c - 'a';
            if (root->childs[i] == nullptr) {
                root->childs[i] = new Trie;
            }
            root = root->childs[i];
        }
        root->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {

        Trie* root = this;
        for (char c : word) {
            int i = c - 'a';
            if (root->childs[i] == nullptr) {
                return false;
            }
            root = root->childs[i];
        }
        return root->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        Trie* root = this;
        for (char c : prefix) {
            int i = c - 'a';
            if (root->childs[i] == nullptr) {
                return false;
            }
            root = root->childs[i];
        }
        return true;
    }

private:
    Trie* childs[26] { nullptr };
    bool isWord = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */