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
    bool hasPathSum(TreeNode* root, int sum) {

        queue<pair<TreeNode*, int>> q;
        if (root) q.emplace(root, sum);
        while (!q.empty()) {
            auto [node, sum] = q.front();
            q.pop();
            sum -= node->val;
            if (!node->left && !node->right) {
                if (sum == 0) return true;
                continue;
            }
            if (node->left) q.emplace(node->left, sum);
            if (node->right) q.emplace(node->right, sum);
        }
        return false;
    }
};