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

        Node dummy;
        Node* prev = &dummy;
        while (root) {
            Node* left = root->left;
            if (left) {
                while (left->right && left->right != root) {
                    left = left->right;
                }
                if (!left->right) {
                    left->right = root;
                    root = root->left;
                    continue;
                }
                left->right = nullptr;
            }
            prev->right = root;
            root->left = prev;
            prev = root;
            root = root->right;
        }
        prev->right = dummy.right;
        dummy.right->left = prev;
        return dummy.right;
    }
};