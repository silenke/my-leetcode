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
    int diameterOfBinaryTree(TreeNode* root) {

        int res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return -1;
            int l = dfs(root->left) + 1;
            int r = dfs(root->right) + 1;
            res = max(res, l + r);
            return max(l, r);
        };
        dfs(root);
        return res;
    }
};