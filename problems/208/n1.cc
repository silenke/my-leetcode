#include "..\..\leetcode.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        Node* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->childs[i] == nullptr) {
                curr->childs[i] = new Node;
            }
            curr = curr->childs[i];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {

        Node* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->childs[i] == nullptr) {
                return false;
            }
            curr = curr->childs[i];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        Node* curr = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (curr->childs[i] == nullptr) {
                return false;
            }
            curr = curr->childs[i];
        }
        return true;
    }

private:
    struct Node {
        bool isWord = false;
        Node* childs[26] { nullptr };
    };

    Node* root = new Node;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */