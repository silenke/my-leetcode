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
        
        dfs(root);
        if (head != nullptr) {
            head->left = prev;
            prev->right = head;
        }
        return head;
    }

private:
    Node* head = nullptr;
    Node* prev = nullptr;

    void dfs(Node* root) {
        
        if (root == nullptr) return;

        dfs(root->left);
        if (head == nullptr) {
            head = root;
        }
        if (prev != nullptr) {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        dfs(root->right);
    }
};