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
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        while (!curr.empty()) {
            long long sum = 0;
            for (const auto& node : curr) {
                sum += node->val;
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            res.push_back(static_cast<double>(sum) / curr.size());
            curr.swap(next);
            next.clear();
        }
        return res;
    }
};