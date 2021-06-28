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
    int sumNumbers(TreeNode* root) {

        int res = 0;
        queue<pair<TreeNode*, int>> q;
        if (root) q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, num] = q.front(); q.pop();
            num = num * 10 + node->val;
            if (!node->left && !node->right) {
                res += num;
                continue;
            }
            if (node->left) q.emplace(node->left, num);
            if (node->right) q.emplace(node->right, num);
        }
        return res;
    }
};