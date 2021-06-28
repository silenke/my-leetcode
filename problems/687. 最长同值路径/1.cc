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
    int longestUnivaluePath(TreeNode* root) {

        return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode* root) {
        // （最长路径，以root为根的最长路径）

        if (root == nullptr) return {0, 0};

        auto [lres, lmax] = dfs(root->left);
        auto [rres, rmax] = dfs(root->right);

        if (root->left && root->left->val == root->val) lmax++;
        else lmax = 0;
        if (root->right && root->right->val == root->val) rmax++;
        else rmax = 0;

        return {max(max(lres, rres), lmax + rmax), max(lmax, rmax)};
    }
};