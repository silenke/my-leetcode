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
    int kthSmallest(TreeNode* root, int k) {

        int res = -1;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return;
            dfs(root->left);
            if (k < 1) return;
            if (k-- == 1) res = root->val;
            else dfs(root->right);
        };
        dfs(root);
        return res;
    }
};