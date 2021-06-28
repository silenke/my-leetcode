#include "..\..\leetcode.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {

        if (!root) return nullptr;
        
        Node* res = nullptr;
        Node* prev = nullptr;
        function<void(Node*)> dfs = [&](Node* root) {
            if (!root) return;
            dfs(root->left);
            if (!prev) {
                res = root;
            }
            else {
                prev->right = root;
                root->left = prev; 
            }
            prev = root;
            dfs(root->right);
        };
        dfs(root);
        prev->right = res;
        res->left = prev;
        return res;
    }
};