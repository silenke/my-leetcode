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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

private:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {

        if (root == nullptr) return;

        targetSum -= root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0) {
                res.emplace_back(path);
            }
        }
        dfs(root->left, targetSum, path, res);
        dfs(root->right, targetSum, path, res);
        path.pop_back();
    }
};