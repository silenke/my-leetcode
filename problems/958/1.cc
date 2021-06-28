#include "..\..\leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        if (root) q.emplace(root);
        bool leaf = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left && node->right) return false;
            if (leaf && (node->left || node->right)) return false;
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
            else leaf = true;
        }
        return true;
    }
};