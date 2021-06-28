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
    int rob(TreeNode* root) {

        auto [i, o] = dfs(root);
        return max(i, o);
    }

private:
    pair<int, int> dfs(TreeNode* root) {

        if (!root) return {0, 0};

        auto [li, lo] = dfs(root->left);
        auto [ri, ro] = dfs(root->right);
        return {root->val + lo + ro, max(li, lo) + max(ri, ro)};
    }
};