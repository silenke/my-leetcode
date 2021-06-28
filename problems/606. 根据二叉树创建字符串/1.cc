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
    string tree2str(TreeNode* t) {

        string res;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return;
            res += to_string(root->val);
            if (!root->left && !root->right) return;
            res += "(";
            dfs(root->left);
            res += ")";
            if (!root->right) return;
            res += "(";
            dfs(root->right);
            res += ")";
        };
        dfs(t);
        return res;
    }
};