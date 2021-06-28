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
        
        TreeNode* res = nullptr;
        TreeNode* prev = nullptr;
        while (root) {
            TreeNode* left = root->left;
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
            if (prev == p) res = root;
            prev = root;
            root = root->right;
        }
        return res;
    }
};