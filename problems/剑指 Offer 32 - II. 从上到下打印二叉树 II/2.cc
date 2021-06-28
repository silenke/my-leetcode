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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (!root) return;
            if (d == res.size()) res.emplace_back();
            res[d++].emplace_back(root->val);
            dfs(root->left, d);
            dfs(root->right, d);
        };
        dfs(root, 0);
        return res;
    }
};