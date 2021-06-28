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
        
        return inorder(root, p);
    }

private:
    TreeNode* pre = nullptr;

    TreeNode* inorder(TreeNode* root, TreeNode* p) {

        if (root == nullptr) return nullptr;

        TreeNode* left = inorder(root->left, p);
        if (left) return left;

        if (pre == p) return root;

        pre = root;
        return inorder(root->right, p);
    }
};