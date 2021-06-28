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
    int getMinimumDifference(TreeNode* root) {

        res = INT_MAX;
        prev = nullptr;
        dfs(root);
        return res;
    }

private:
    int res;
    TreeNode* prev;

    void dfs(TreeNode* root) {

        if (root == nullptr) return;

        dfs(root->left);
        if (prev) res = min(res, root->val - prev->val);
        prev = root;
        dfs(root->right);
    }
};