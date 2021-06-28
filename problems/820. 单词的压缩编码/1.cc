#include "..\..\leetcode.h"

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        for (const string& w : words) {
            insert(w);
        }
        int res = 0;
        for (Node* n : nodes) {
            if (n->leaf) res += n->len + 1;
        }
        return res;
    }

private:
    struct Node {
        bool leaf = true;
        int len = 0;
        Node* childs[26]{nullptr};
    };

    Node* root = new Node;
    unordered_set<Node*> nodes;

    void insert(const string& w) {

        Node* curr = root;
        for (int i = w.size() - 1; i >= 0; i--) {
            int j = w[i] - 'a';
            if (curr->childs[j] == nullptr) {
                curr->childs[j] = new Node;
                curr->leaf = false;
            }
            curr = curr->childs[j];
        }
        curr->len = w.size();
        nodes.insert(curr);
    }
};