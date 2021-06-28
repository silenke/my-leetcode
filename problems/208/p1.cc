#include "..\..\leetcode.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root_(new Node) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        Node* curr = root_.get();
        for (char c : word) {
            int i = c - 'a';
            if (!curr->childs[i]) {
                curr->childs[i] = new Node;
            }
            curr = curr->childs[i];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) const {

        const Node* node = find(word);
        return (node && node->isWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) const {

        return find(prefix);
    }

private:
    struct Node {
        bool isWord;
        vector<Node*> childs;
        Node() : isWord(false), childs(26, nullptr) {}
        ~Node() {
            for (Node* c : childs) {
                if (c) delete c;
            }
        }
    };
    
    const Node* find(const string& prefix) const {

        const Node* curr = root_.get();
        for (char c : prefix) {
            curr = curr->childs[c - 'a'];
            if (!curr) break;
        }
        return curr;
    }

    unique_ptr<Node> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */