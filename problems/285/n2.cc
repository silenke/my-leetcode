#include "..\..\leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        TreeNode* prev = nullptr;
        return inorder(root, p, prev);
    }

private:
    TreeNode* inorder(TreeNode* root, TreeNode* p, TreeNode*& prev) {

        if (root == nullptr) return nullptr;

        TreeNode* left = inorder(root->left, p, prev);
        if (left) return left;

        if (prev == p) return root;

        prev = root;
        return inorder(root->right, p, prev);
    }
};