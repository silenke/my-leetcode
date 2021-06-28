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
    TreeNode* mirrorTree(TreeNode* root) {

        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            swap(curr->left, curr->right);
            if (curr->left) q.emplace(curr->left);
            if (curr->right) q.emplace(curr->right);
        }
        return root;
    }
};