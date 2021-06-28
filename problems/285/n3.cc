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
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.emplace(root);
                root = root->left;
            }
            else {
                root = s.top(); s.pop();
                if (prev == p) return root;
                prev = root;
                root = root->right;
            }
        }
        return nullptr;
    }
};