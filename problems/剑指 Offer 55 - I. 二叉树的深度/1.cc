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
    int maxDepth(TreeNode* root) {

        int res = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (root == 0) return;
            if (++d > res) res = d;
            dfs(root->left, d);
            dfs(root->right, d);
        };
        dfs(root, 0);
        return res;
    }
};