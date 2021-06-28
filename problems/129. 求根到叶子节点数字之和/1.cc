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
    int sumNumbers(TreeNode* root) {

        int res = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int num) {
            if (!root) return;
            num = num * 10 + root->val;
            if (!root->left && !root->right) {
                res += num;
                return;
            }
            dfs(root->left, num);
            dfs(root->right, num);
        };
        dfs(root, 0);
        return res;
    }
};