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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int depth) {
            if (!root) return;
            if (depth == res.size()) res.push_back(root->val);
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
        };
        dfs(root, 0);
        return res;
    }
};