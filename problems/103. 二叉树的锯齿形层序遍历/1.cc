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
        deque<TreeNode*> dq;
        if (root) dq.push_back(root);
        bool right = true;
        while (!dq.empty()) {
            int n = dq.size();
            res.push_back(vector<int>(n));
            for (int i = 0; i < n; i++) {
                if (right) {
                    TreeNode* curr = dq.front(); dq.pop_front();
                    res.back()[i] = curr->val;
                    if (curr->left) dq.push_back(curr->left);
                    if (curr->right) dq.push_back(curr->right);
                }
                else {
                    TreeNode* curr = dq.back(); dq.pop_back();
                    res.back()[i] = curr->val;
                    if (curr->right) dq.push_front(curr->right);
                    if (curr->left) dq.push_front(curr->left);
                }
            }
            right ^= 1;
        }
        return res;
    }
};