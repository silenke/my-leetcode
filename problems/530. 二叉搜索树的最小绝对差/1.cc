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

        int pre = INT_MAX;
        return dfs(root, pre);
    }

private:
    int dfs(TreeNode* root, int& pre) {
        
        if (root == nullptr) return INT_MAX;

        int res = dfs(root->left, pre);
        res = min(res, abs(root->val - pre));
        pre = root->val;
        return min(res, dfs(root->right, pre));
    }
};