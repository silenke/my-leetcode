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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (!root) return;
            if (d == res.size()) res.emplace_back();
            res[d].emplace_back(root->val);
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        };
        dfs(root, 0);
        return res;
    }
};