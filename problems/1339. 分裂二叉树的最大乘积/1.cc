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
    int maxProduct(TreeNode* root) {

        const int kMod = 1e9 + 7;
        function<int(TreeNode*)> sum = [&](TreeNode* root) {
            if (!root) return 0;
            return root->val + sum(root->left) + sum(root->right);
        };
        long s = sum(root);
        long res = 0;
        function<int(TreeNode*)> solve = [&](TreeNode* root) {
            if (!root) return 0;
            int l = solve(root->left);
            int r = solve(root->right);
            res = max({res, l * (s - l), (s - r) * r});
            return l + root->val + r;
        };
        solve(root);
        return res % kMod;
    }
};