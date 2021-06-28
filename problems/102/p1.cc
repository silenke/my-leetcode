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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {

            int n = q.size();
            res.emplace_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                res.back()[i] = node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return res;
    }
};