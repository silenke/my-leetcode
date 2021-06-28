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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        vector<int> p;
        dfs(root, p, res);
        return res;
    }

private:
    void dfs(TreeNode* root, vector<int>& p, vector<string>& res) {

        if (!root) return;

        if (!root->left && !root->right) {
            res.emplace_back();
            for (int n : p) {
                res.back().append(to_string(n) + "->");
            }
            res.back().append(to_string(root->val));
            return;
        }
        p.emplace_back(root->val);
        dfs(root->left, p, res);
        dfs(root->right, p, res);
        p.pop_back();
    }
};