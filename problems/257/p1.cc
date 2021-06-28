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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        dfs(root, "", res);
        return res;
    }

private:
    void dfs(TreeNode* root, string s, vector<string>& res) {
        
        if (root == nullptr) return;

        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.emplace_back(s);
            return;
        }
        
        s += "->";
        dfs(root->left, s, res);
        dfs(root->right, s, res);
    }
};