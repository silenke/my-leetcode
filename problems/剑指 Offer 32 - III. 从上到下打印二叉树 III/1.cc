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
        deque<TreeNode*> dq;
        if (root) dq.emplace_back(root);
        bool rl = true;    // 下一层从右往左打印
        while (!dq.empty()) {
            int n = dq.size();
            res.emplace_back(n);
            for (int i = 0; i < n; i++) {
                if (rl) {
                    root = dq.front(); dq.pop_front();
                    res.back()[i] = root->val;
                    if (root->left) dq.emplace_back(root->left);
                    if (root->right) dq.emplace_back(root->right);
                }
                else {
                    root = dq.back(); dq.pop_back();
                    res.back()[i] = root->val;
                    if (root->right) dq.emplace_front(root->right);
                    if (root->left) dq.emplace_front(root->left);
                }
            }
            rl ^= 1;
        }
        return res;
    }
};