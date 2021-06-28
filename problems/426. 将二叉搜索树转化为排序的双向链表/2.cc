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

        if (root == nullptr) return nullptr;

        Node dummyHead;
        Node* prev = &dummyHead;
        dfs(root, prev);
        prev->right = dummyHead.right;
        dummyHead.right->left = prev;
        return dummyHead.right;
    }

private:
    void dfs(Node* root, Node*& prev) {

        if (root == nullptr) return;

        dfs(root->left, prev);
        prev->right = root;
        root->left = prev;
        prev = root;
        dfs(root->right, prev);
    }
};