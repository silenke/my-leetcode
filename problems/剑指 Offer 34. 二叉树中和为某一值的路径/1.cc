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
    vector<vector<int>> pathSum(TreeNode* root, int target) {

        vector<vector<int>> res;
        vector<int> p;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int target) {
            if (!root) return;
            p.emplace_back(root->val);
            target -= root->val;
            if (!root->left && !root->right && !target) {
                res.emplace_back(p);
            }
            dfs(root->left, target);
            dfs(root->right, target);
            p.pop_back();
        };
        dfs(root, target);
        return res;
    }
};