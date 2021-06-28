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
    int maxPathSum(TreeNode* root) {

        return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode* root) {
        // （最大路径和，以root为根的最大路径和）

        if (root == nullptr) return {INT_MIN, 0};

        auto [lres, lmax] = dfs(root->left);
        auto [rres, rmax] = dfs(root->right);

        if (lmax < 0) lmax = 0;
        if (rmax < 0) rmax = 0;
        return {max(max(lres, rres), lmax + rmax + root->val), max(lmax, rmax) + root->val};
    }
};