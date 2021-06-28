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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool lr = true;
        while (!q.empty()) {
            int n = q.size();
            res.push_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front(); q.pop();
                res.back()[lr ? i : n - 1 - i] = curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            lr ^= 1;
        }
        return res;
    }
};