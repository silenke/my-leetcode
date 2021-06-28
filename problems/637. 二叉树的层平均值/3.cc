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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [val, left, right] = *q.front(); q.pop();
                sum += val;
                if (left) q.push(left);
                if (right) q.push(right);
            }
            res.push_back(static_cast<double>(sum) / n);
        }
        return res;
    }
};