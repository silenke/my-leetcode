#include "..\..\leetcode.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {

        vector<int> res;
        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) return;
            res.emplace_back(root->val);
            for (Node* c : root->children) dfs(c);
        };
        dfs(root);
        return res;
    }
};