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

        TreeNode* prev = nullptr;
        return dfs(root, prev);
    }

private:
    int dfs(TreeNode* root, TreeNode*& prev) {
        
        if (root == nullptr) return INT_MAX;

        int res = dfs(root->left, prev);
        if (prev) res = min(res, root->val - prev->val);
        prev = root;
        return min(res, dfs(root->right, prev));
    }
};