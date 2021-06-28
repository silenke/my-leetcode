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
    int kthLargest(TreeNode* root, int k) {

        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return 0;
            int res = dfs(root->right);
            if (k <= 0) return res;
            if (--k == 0) return root->val;
            return dfs(root->left);
        };
        return dfs(root);
    }
};